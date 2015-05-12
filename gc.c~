#include "gc.h"
#include <stdio.h>
#include <string.h> //for memcpy()

//"private" methods
void obj_mark(Object* obj);
void ref_add(void* ptr);
void ref_remove(Reference* ref);
void var_disposeAll();
void ref_disposeAll();
void var_dispose(Variable* var);
void ref_dispose(Reference* ref);
void obj_dispose(Object* obj);
void freeReferences();
Object* var_getObject(Variable* var);

//Global Variables
VarStack 	variableStack = {0,NULL};
RefList 	referenceList = {0,NULL,NULL};
RefList		freeList = {0,NULL,NULL};
unsigned char	currentMark;

#ifdef DIAGNOSTIC
unsigned int 	diag_totalObjectsAllocated = 0;
unsigned long 	diag_totalMemAllocated = 0;
unsigned int	diag_totalVarsPushed = 0;
unsigned int	diag_totalVarsPopped = 0;
unsigned int	diag_totalCollected = 0;
unsigned int 	diag_totalFreed = 0;
unsigned int 	diag_allocatedObjectsSinceLastCheck = 0;
unsigned int	diag_pushedVarsSinceLastCheck = 0;
unsigned int	diag_poppedVarsSinceLastCheck = 0;
unsigned int	diag_allocatedMemSinceLastCheck = 0;
unsigned int	diag_collectedSinceLastCheck = 0;
unsigned int	diag_freedSinceLastCheck = 0;
#endif

#ifdef TRACE
int tabCount = 0;
#endif

Variable* new_variable(void* addr)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("new_variable(%p)\n", addr);
	#endif
	
	Variable* newVar = allocate_mem(sizeof(Variable));
	if(newVar == NULL){
		printf("New Variable failed to be allocated\n");
		
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL\n");
		tabCount--;
		#endif
		
		return NULL;
	}

	newVar->next = NULL;
	newVar->address = (void***)addr;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", newVar);
	tabCount--;
	#endif
	return newVar;
}

Reference* new_reference(void* obj)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("new_reference(%p)\n", obj);
	#endif
	
	Reference* newRef = allocate_mem(sizeof(Reference));
	if(newRef == NULL){
		printf("New Reference failed to be allocated\n");
		
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL\n");
		tabCount--;
		#endif
		
		return NULL;
	}

	newRef->next = NULL;
	newRef->prev = NULL;
	newRef->value = (Object*)obj;

	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", newRef);
	tabCount--;
	#endif
	
	return newRef;
}

Object* new_object(int childNum, void** childList)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("new_object(%d, %p)\n", childNum, childList);
	#endif
	
	Object* newObj = allocate_mem(sizeof(Object));
	if(newObj == NULL){
		printf("New Object failed to be allocated\n");
		
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL\n");
		tabCount--;
		#endif
		return NULL;
	}

	newObj->mark = currentMark;
	newObj->childNum = childNum;
	newObj->childList = (Object**) childList;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", newObj);
	tabCount--;
	#endif

	return newObj;
}

void* allocate_mem(size_t size)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("allocate_mem(%d)\n", size);
	#endif
	
	void* ptr = malloc(size);
	
	if(ptr != NULL)
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return %p\n", ptr);
		tabCount--;
		#endif
		return ptr;
	}
	
	gc_collect();
	
	ptr = malloc(size);
	
	if(ptr == NULL)
	{
		printf("Cannot allocate memory\n");
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL\n");
		tabCount--;
		#endif
		return NULL;
	}
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", ptr);
	tabCount--;
	#endif
	
	return ptr;
}

Object* var_getObject(Variable* var)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("var_getObject(%p)\n", var);
	#endif
	
	if(*(var->address) != NULL)
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return (%p)\n", (Object*)**(var->address));
		tabCount--;
		#endif
		return (Object*)**(var->address);
	}
	else
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL;\n");
		tabCount--;
		#endif
		return NULL;
	}
}

Object* obj_getChild(void* ptr)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("obj_getChild(%p)\n", ptr);
	#endif
	
	if(*(void**) ptr == NULL)
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL\n");
		tabCount--;
		#endif
		return NULL;
	}
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", (Object*)**((void***)ptr));
	tabCount--;
	#endif
	
	return (Object*)**((void***)ptr);
}

void var_push(void* addr)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("var_push(%p)\n", addr);
	#endif
	
	Variable* newVar = new_variable(addr);

	newVar->next = variableStack.head;
	variableStack.head = newVar;
	
	#ifdef DIAGNOSTIC
	diag_totalVarsPushed++;
	diag_pushedVarsSinceLastCheck++;
	#endif
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void var_pop()
{
	Variable* poppedVar = variableStack.head;

	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("var_pop()\n");
	#endif
	
	if(poppedVar == NULL)
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return (premature)\n");
		tabCount--;
		#endif
		return;
	}

	variableStack.head = variableStack.head->next;

	var_dispose(poppedVar);
	
	#ifdef DIAGNOSTIC
	diag_totalVarsPopped++;
	diag_poppedVarsSinceLastCheck++;
	#endif
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void* gc_malloc(size_t size, Object* obj)
{
	void** ptr = allocate_mem(size);

	#ifdef DIAGNOSTIC
	diag_allocatedMemSinceLastCheck += size + sizeof(Reference);
	diag_allocatedObjectsSinceLastCheck++;
	diag_totalMemAllocated += size + sizeof(Reference);
	diag_totalObjectsAllocated++;
	#endif
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("gc_malloc(%d,%p)\n", size, obj);
	#endif
	
	if(ptr == NULL){
		#ifdef TRACE
		print_tabs(tabCount); printf("return NULL\n");
		tabCount--;
		#endif
		printf("Could not allocate memory\n");
		return NULL;
	}

	ptr[0] = (void*) obj;

	ref_add(*ptr);
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", (void*)ptr);
	tabCount--;
	#endif

	return (void*)ptr;
}

void gc_mark()
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("gc_mark()\n");
	#endif
	
	currentMark++;

	Variable* currentNode = variableStack.head;

	while(currentNode != NULL)
	{
		obj_mark(var_getObject(currentNode));
		currentNode = currentNode->next;
	}
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void obj_mark(Object* obj)
{
	int i;
	
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("obj_mark(%p)\n", obj);
	#endif
	
	if(obj == NULL || obj->mark == currentMark)
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return (premature)\n");
		tabCount--;
		#endif
		return;
	}

	obj->mark = currentMark;

	for(i = 0; i < obj->childNum; i++)
	{
		obj_mark(obj_getChild(obj->childList[i]));
	}
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void gc_sweep()
{
	Reference* currentNode = referenceList.head;
	Reference* nextNode;

	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("gc_sweep()\n");
	#endif
	
	while(currentNode != NULL)
	{
		nextNode = currentNode->next;
		if(currentNode->value->mark != currentMark)
		{
			ref_remove(currentNode);

			#ifdef DIAGNOSTIC
			diag_collectedSinceLastCheck++;
			diag_totalCollected++;
			#endif
		}
		currentNode = nextNode;
	}
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void gc_dispose()
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("gc_dispose()\n");
	#endif
	
	var_disposeAll();
	ref_disposeAll();
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void gc_collect()
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("gc_collect()\n");
	#endif
	
	gc_mark();
	gc_sweep();
	freeReferences();
	print_gc();
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void ref_add(void* ptr)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("ref_add(%p)\n", ptr);
	#endif
	
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
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void ref_remove(Reference* ref)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("ref_remove(%p)\n", ref);
	#endif
	
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
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void var_disposeAll()
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("var_disposeAll()\n");
	#endif
	
	while(variableStack.head != NULL)
	{
		var_pop();
	}
	variableStack.size = 0;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void ref_disposeAll()
{
	Reference* currentNode = referenceList.head;
	Reference* nextNode;

	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("ref_disposeAll()\n");
	#endif
	
	while(currentNode != NULL)
	{
		nextNode = currentNode->next;
		ref_dispose(currentNode);
		currentNode = nextNode;
	}

	referenceList.head = NULL;
	referenceList.tail = NULL;
	referenceList.size = 0;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void var_dispose(Variable* var)
{
	//should not free the object
	//the reference list will handle that
	//obj_dispose(var->value);

	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("var_dispose(%p)\n", var);
	#endif
	
	free(var);
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void ref_dispose(Reference* ref)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("ref_dispose(%p)\n", ref);
	#endif
	
	obj_dispose(ref->value);

	free(ref);
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void obj_dispose(Object* obj)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("obj_dispose(%p)\n", obj);
	#endif
	
	if(obj->childList != NULL)
		free(obj->childList);

	free(obj);
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void freeReferences()
{
	Reference* currentNode;

	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("freeReferences()\n");
	#endif
	
	if(freeList.size < MAXFREELIST)
	{
		#ifdef TRACE
		print_tabs(tabCount); printf("return (premature)\n");
		tabCount--;
		#endif
		
		return;
	}

	while(freeList.head != NULL)
	{
		currentNode = freeList.head->next;
		ref_dispose(freeList.head);
		freeList.head = currentNode;

		#ifdef DIAGNOSTIC
		diag_freedSinceLastCheck++;
		diag_totalFreed++;
		#endif
	}

	freeList.size = 0;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

IntElement* New_Integer(int x)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("New_Integer(%d)\n", x);
	#endif
	
	Object* obj = new_object(0,NULL);
	IntElement* ptr = gc_malloc(sizeof(IntElement), obj);
	ptr->value = x;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", ptr);
	tabCount--;
	#endif
	
	return ptr;
}

BoolElement* New_Boolean(bool x)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("New_Boolean(%d)\n", x);
	#endif
	
	Object* obj = new_object(0, NULL);
	BoolElement* ptr = gc_malloc(sizeof(BoolElement), obj);
	ptr->value = x;
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", ptr);
	tabCount--;
	#endif
	
	return ptr;
}

Array* New_Array(int n)
{
	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("New_Array(%d)\n", n);
	#endif
	
	Object* obj;
	Array* ptr;
	void** childList = allocate_mem(sizeof(void*) * n);
	int i;
	
	obj = new_object(n, childList);
	ptr = gc_malloc(sizeof(Array), obj);
	
	ptr->elemNum = n;
	ptr->address = allocate_mem(sizeof(void*) * n);
	for(i = 0; i < n; i++)
	{
		ptr->address[i] = NULL;
		childList[i] = &(ptr->address[i]);
	}
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return %p\n", ptr);
	tabCount--;
	#endif
	
	return ptr;
}

#ifdef DEBUG
void print_object(int tabNum, Object* obj)
{
	print_tabs(tabNum); printf("obj = %p\n", obj);
	if(obj == NULL) return;
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
	print_tabs(tabNum); printf("addr = %p\n", var->address);
	print_object(tabNum+1, var_getObject(var));
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
		//printf("%p", *((void**)array[i]));
		
		printf("%p", obj_getChild(array[i]));

		if(i != size-1) printf(",");
	}

	printf("}");
}
#endif

void print_refList()
{
	#ifdef DEBUG
	Reference* currentNode = referenceList.head;

	printf("Reference List:\n");

	while(currentNode != NULL)
	{
		print_reference(1, currentNode);
		currentNode = currentNode->next;
	}
	#endif
}

void print_varStack()
{
	#ifdef DEBUG
	Variable* currentNode = variableStack.head;

	printf("Variable Stack:\n");

	while(currentNode != NULL)
	{
		print_variable(1, currentNode);
		currentNode = currentNode->next;
	}
	#endif
}

void print_freeList()
{
	#ifdef DEBUG
	Reference* currentNode = freeList.head;
	printf("FreeList:\n");

	while(currentNode != NULL)
	{
		print_reference(1, currentNode);
		currentNode = currentNode->next;
	}
	#endif
}

void print_tabs(int tabNum)
{
	int i;

	for(i = 0; i < tabNum; i++)
	{
		printf("\t");
	}
}

void print_gc()
{
	#ifdef DIAGNOSTIC
	print_diagnostics();
	#endif
	#ifdef DEBUG
	printf("\nCurrent Mark = %d\n", currentMark);
	print_varStack();
	print_refList();
	print_freeList();
	printf("\n");
	#endif
}

void init_struct(void** childList, int childNum, ...)
{
	//Variadic variables here are the address pointers to the structs members
	void** tempArg;
	int argNum;
	va_list args;
	va_start(args, childNum);

	#ifdef TRACE
	tabCount++;
	print_tabs(tabCount); printf("init_struct(%p, %d, ...)\n", childList, childNum);
	#endif
	
	argNum = childNum;

	while(childNum--)
	{
		tempArg = va_arg(args, void**);
		*tempArg = NULL;
		childList[argNum - childNum - 1] = tempArg;
	}
	va_end(args);
	
	#ifdef TRACE
	print_tabs(tabCount); printf("return\n");
	tabCount--;
	#endif
}

void print_diagnostics()
{
	#ifdef DIAGNOSTIC
	
	printf("Allocated\t%d objects (%d bytes) since last print\n", diag_allocatedObjectsSinceLastCheck, diag_allocatedMemSinceLastCheck);
	printf("Allocated\t%d objects (%d bytes) total\n", diag_totalObjectsAllocated, diag_totalMemAllocated);
	printf("Pushed\t\t%d Variables and Popped %d Variables since last print\n", diag_pushedVarsSinceLastCheck, diag_poppedVarsSinceLastCheck);
	printf("Pushed\t\t%d Variables and Popped %d Variables total\n", diag_totalVarsPushed, diag_totalVarsPopped);
	printf("Collected\t%d Objects for freeing since last print\n", diag_collectedSinceLastCheck);
	printf("Collected\t%d Object for freeing in total\n", diag_totalCollected);
	printf("Freed\t\t%d objects since last print\n", diag_freedSinceLastCheck);
	printf("Freed\t\t%d Objects total\n\n", diag_totalFreed);
	
	diag_allocatedObjectsSinceLastCheck = 0;
	diag_allocatedMemSinceLastCheck = 0;
	diag_freedSinceLastCheck = 0;
	diag_poppedVarsSinceLastCheck = 0;
	diag_pushedVarsSinceLastCheck = 0;
	
	#endif
}
