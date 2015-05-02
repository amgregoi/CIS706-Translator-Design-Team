#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "gc.h"

#define typeof(x) (x == "int")? PRIMITIVE : REFERENCE

void printRefs()
{
	Reference* currentNode = gc_referenceList.head;
	
	printf("RefList %d elements\n\t", gc_referenceList.size);
	
	while(currentNode != NULL)
	{
		printf(" %p ->", currentNode->value.pointer);
		currentNode = currentNode->next;
	}
	
	printf(" NULL\n");
}

void printVars()
{
	StackNode* currentNode = gc_variableStack.head;
	void ** variableAddress;
	void * variableValue;
	
	printf("VarStack %d elements\n\t", gc_variableStack.size);
	
	while(currentNode != NULL)
	{
		variableAddress = &(currentNode->value);
		variableValue = currentNode->value;
		
		printf(" %p[%p] ->", variableAddress, variableValue);
		currentNode = currentNode->next;
	}
	
	printf(" NULL\n");
}

typedef struct sTestStruct{
	struct sTestStruct* pointer;
} TestStruct;

int main()
{
	TestStruct* newStruct = malloc(sizeof(TestStruct));
	TestStruct* subStruct = malloc(sizeof(TestStruct));
	
	newStruct->pointer = NULL;
	
	Reference* newRef = New_Reference(*New_Object((void*)&newStruct,1));
	newRef->value.childList[0] = (void*)&(newStruct->pointer);
	
	Reference* ref2 = New_Reference(*New_Object((void*)&subStruct, 1));
	ref2->value.childList[0] = (void*)&(subStruct->pointer);
	
	newStruct->pointer = subStruct;
	
	printRefs();
	addRef(newRef);
	printRefs();
	addRef(ref2);
	printRefs();
	
	gc_Dispose();
	printf("Disposed of Variable Stack and Reference List\n");
	printVars();
	printRefs();
	return 0;
}

void* gc_Malloc(RefType refType)
{
	
}

void gc_Free(void * ptr)
{
	
}

void gc_Mark()
{
	
}

void gc_Sweep()
{
	
}

void gc_Dispose()
{
	disposeVars();
	disposeRefs();
}

void pushVar(ObjectType objType, void* varAddress)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	
	if(newNode == NULL)
	{
		printf("Could not allocate any more memory\n");
		return;
	}
	
	newNode->value = varAddress;
	newNode->next = gc_variableStack.head;	
	gc_variableStack.head = newNode;
	gc_variableStack.size++;
}

void popVar()
{
	if(gc_variableStack.head == NULL) return;
	
	StackNode* tempNode;
	tempNode = gc_variableStack.head;
	gc_variableStack.head = gc_variableStack.head->next;
	free(tempNode);
	gc_variableStack.size--;
}

void disposeVars()
{
	while(gc_variableStack.head != NULL)
	{
		popVar();
	}
	gc_variableStack.size = 0;
}

//TODO link with objects that contain this as a child, link it to any children
//if it has them. Seems like a terrible way to do it
void addRef(Reference* refAddress)
{
	if(gc_referenceList.head == NULL && gc_referenceList.tail == NULL)
	{
		gc_referenceList.head = refAddress;
		gc_referenceList.tail = refAddress;
		refAddress->next = NULL;
		refAddress->prev = NULL;
		return;
	}
	
	refAddress->prev = gc_referenceList.tail;
	refAddress->next = NULL;
	gc_referenceList.tail->next = refAddress;
	gc_referenceList.size++;
	
	linkRef(refAddress);
}

void linkRef(Reference* refAddress)
{
	
}

void removeRef(Reference* refAddress)
{
	Reference* nextNode = refAddress->next;
	Reference* prevNode = refAddress->prev;
	
	if(nextNode != NULL)
		nextNode->prev = prevNode;
	
	if(prevNode != NULL)
		prevNode->next = nextNode;
	
	free(refAddress);
	gc_referenceList.size--;
}

Reference* getRef(void* variableValue)
{
	Reference* currentNode = gc_referenceList.head;
	
	while(currentNode != NULL)
	{
		if(currentNode->value.pointer == variableValue)
			return currentNode;
		
		currentNode = currentNode->next;
	}
	
	return NULL;
}

void disposeRefs()
{
	Reference* currentNode = gc_referenceList.head;
	Reference* nextNode;
	
	while(currentNode != NULL)
	{
		free(currentNode->value.childList);
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	
	gc_referenceList.head = NULL;
	gc_referenceList.tail = NULL;
	gc_referenceList.size = 0;
}