#include "gc.h"
#include <stdio.h>
#include <string.h> //for memcpy()

//Global Variables
VarStack 	variableStack = {0,NULL};
RefList 	referenceList = {0,NULL,NULL};
RefList		freeList = {0,NULL,NULL};
unsigned char	currentMark;

Variable* new_variable(int ID, void** addr)
{
	Variable* newVar = malloc(sizeof(Variable));
	if(newVar == NULL){
		printf("New Variable failed to be allocated\n");
		return NULL;
	}

	newVar->ID = ID;
	newVar->next = NULL;
	newVar->address = addr;
	return newVar;
}

Reference* new_reference(void* obj)
{
	Reference* newRef = malloc(sizeof(Reference));
	if(newRef == NULL){
		printf("New Reference failed to be allocated\n");
		return NULL;
	}

	newRef->next = NULL;
	newRef->prev = NULL;
	newRef->value = (Object*)obj;

	return newRef;
}

Object* new_object(int childNum, void** childList)
{
	Object* newObj = malloc(sizeof(Object));
	if(newObj == NULL){
		printf("New Object failed to be allocated\n");
		return NULL;
	}

	newObj->mark = currentMark;
	newObj->childNum = childNum;
	newObj->childList = (Object**) childList;

	return newObj;
}

Object* var_getObject(Variable* var)
{
	return (Object*)(var->address[0]);
}

void var_push(int ID, void** addr)
{
	Variable* newVar = new_variable(ID, addr);

	newVar->next = variableStack.head;
	variableStack.head = newVar;
}

void var_pop()
{
	Variable* poppedVar = variableStack.head;

	if(poppedVar == NULL) return;

	variableStack.head = variableStack.head->next;

	var_dispose(poppedVar);
}

void* gc_malloc(size_t size, Object* obj)
{
	void** ptr = malloc(size);

	if(ptr == NULL){
		printf("Could not allocate memory\n");
		return NULL;
	}

	ptr[0] = (void*) obj;

	ref_add(*ptr);

	return (void*)ptr;
}

void gc_mark()
{
	currentMark++;

	Variable* currentNode = variableStack.head;

	while(currentNode != NULL)
	{
		obj_mark(var_getObject(currentNode));
		currentNode = currentNode->next;
	}
}

void obj_mark(Object* obj)
{
	int i;

	if(obj == NULL || obj->mark == currentMark) return;

	obj->mark = currentMark;

	for(i = 0; i < obj->childNum; i++)
	{
		obj_mark(obj->childList[i]);
	}
}

void gc_sweep()
{
	Reference* currentNode = referenceList.head;
	Reference* nextNode;

	while(currentNode != NULL)
	{
		nextNode = currentNode->next;
		if(currentNode->value->mark != currentMark)
		{
			ref_remove(currentNode);
		}
		currentNode = nextNode;
	}
}

void gc_dispose()
{
	var_disposeAll();
	ref_disposeAll();
}

void gc_collect()
{
	gc_mark();
	gc_sweep();
	freeReferences();
#ifdef DEBUG
	print_gc();
#endif
}

void ref_add(void* ptr)
{
	Reference* ref = new_reference(ptr);

	if(referenceList.head == NULL && referenceList.tail == NULL)
	{
		referenceList.head = ref;
		referenceList.tail = ref;
		ref->next = NULL;
		ref->prev = NULL;
	} else{

		ref->next = NULL;
		ref->prev = referenceList.tail;
		referenceList.tail->next = ref;
		referenceList.tail = ref;
	}

	referenceList.size++;
}

void ref_remove(Reference* ref)
{
	if(referenceList.tail == ref)
		referenceList.tail = ref->prev;

	if(referenceList.head == ref)
		referenceList.head = ref->next;

	if(ref->prev != NULL)
		ref->prev->next = ref->next;

	if(ref->next != NULL)
		ref->next->prev = ref->prev;

	ref->next = freeList.head;
	freeList.head = ref;
	freeList.size++;
}

void var_disposeAll()
{
	while(variableStack.head != NULL)
	{
		var_pop();
	}
	variableStack.size = 0;
}

void ref_disposeAll()
{
	Reference* currentNode = referenceList.head;
	Reference* nextNode;

	while(currentNode != NULL)
	{
		nextNode = currentNode->next;
		ref_dispose(currentNode);
		currentNode = nextNode;
	}

	referenceList.head = NULL;
	referenceList.tail = NULL;
	referenceList.size = 0;
}

void var_dispose(Variable* var)
{
	//should not free the object
	//the reference list will handle that
	//obj_dispose(var->value);

	free(var);
}

void ref_dispose(Reference* ref)
{
	obj_dispose(ref->value);

	free(ref);
}

void obj_dispose(Object* obj)
{
	if(obj->childList != NULL)
		free(obj->childList);

	free(obj);
}

void freeReferences()
{
	Reference* currentNode;

	if(freeList.size < MAXFREELIST) return;

	while(freeList.head != NULL)
	{
		currentNode = freeList.head->next;
		ref_dispose(freeList.head);
		freeList.head = currentNode;
	}

	freeList.size = 0;
}

#ifdef DEBUG
void print_object(int tabNum, Object* obj)
{
	print_tabs(tabNum); printf("obj = %p\n", obj);
	print_tabs(tabNum); printf("mark = %d\n", obj->mark);
	print_tabs(tabNum); printf("childNum = %d\n", obj->childNum);
	print_tabs(tabNum); printf("childList = ");
	print_array(obj->childNum, (void**)obj->childList); printf("\n");
}

void print_reference(int tabNum, Reference* ref)
{
	print_tabs(tabNum); printf("ref = %p\n", ref);
	print_object(tabNum+1, ref->value);
}

void print_variable(int tabNum, Variable* var)
{
	print_tabs(tabNum); printf("var = %p\n", var);
	print_tabs(tabNum); printf("ID = %d\n", var->ID);
	print_tabs(tabNum); printf("addr = %p\n", var->address);
	print_object(tabNum+1, var_getObject(var));
}

void print_tabs(int tabNum)
{
	int i;

	for(i = 0; i < tabNum; i++)
	{
		printf("\t");
	}
}

void print_array(int size, void** array)
{
	int i;

	if(array == NULL)
	{
		printf("NULL\n");
		return;
	}
	if(size >= 10) size = 10;

	printf("{");
	for(i = 0; i < size; i++)
	{
		printf("%p", array + (i * sizeof(void*)));

		if(i != size-1) printf(",");
	}

	printf("}");
}

void print_refList()
{
	Reference* currentNode = referenceList.head;

	printf("Reference List:\n");

	while(currentNode != NULL)
	{
		print_reference(1, currentNode);
		currentNode = currentNode->next;
	}
}

void print_varStack()
{
	Variable* currentNode = variableStack.head;

	printf("Variable Stack:\n");

	while(currentNode != NULL)
	{
		print_variable(1, currentNode);
		currentNode = currentNode->next;
	}
}

void print_freeList()
{
	Reference* currentNode = referenceList.head;
	printf("FreeList:\n");

	while(currentNode != NULL)
	{
		print_reference(1, currentNode);
		currentNode = currentNode->next;
	}
}

void print_gc()
{
	print_varStack();
	print_refList();
	print_freeList();
}
#endif
