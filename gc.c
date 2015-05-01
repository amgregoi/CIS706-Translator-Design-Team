#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "gc.h"
#include "generatedFile.h"

struct sObject{
	bool mark;
	ObjectType type; //may be unnecessary
	void** pointer;
	Object** childList;
};

struct sStackNode{
	//Object value;
	StackNode* next;
	void * value;
};

struct sStack{
	int size;
	StackNode* head;
};

struct sReference{
	Reference* next;
	Reference* prev;
	Object value;
};

struct sRefList{
	int size;
	Reference* head;
	Reference* tail;
};

//Global Variables
VarStack gc_variableStack = {0,NULL};
RefList gc_referenceList = {0,NULL,NULL};
bool currentMark = true;

//Methods
void* gc_Malloc(size_t);
void gc_Free(void *);
void gc_Mark();
void gc_Sweep();
void gc_Dispose();
void pushVar(ObjectType, ValueType, void *);
void popVar();
void disposeVars();
void addRef(Reference*);
void removeRef(Reference*);
Reference* getRef(void *);
void disposeRefs();
Reference* generateRef(RefType);


void printRefs()
{
	Reference* currentNode = gc_referenceList.head;
	
	printf("RefList = ");
	
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
	
	printf("VarStack = ");
	
	while(currentNode != NULL)
	{
		printf(" %p[%p] ->", currentNode->value, *(currentNode->value));
		currentNode = currentNode->next;
	}
	
	printf(" NULL\n");
}

int main()
{
	return 0;
}

void* gc_Malloc(size_t size)
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

void pushVar(ObjectType objType, ValueType valType, void* varAddress)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	
	newNode->value = varAddress;
	newNode->next = gc_variableStack.head;
	gc_variableStack.head = newNode->next;
	
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

void addRef(Reference* refAddress)
{
	if(gc_referenceList.head == NULL && gc_referenceList.tail == NULL)
	{
		gc_referenceList.head = refAddress;
		gc_referenceList.tail = refAddress;
		return;
	}
	
	refAddress->prev = gc_referenceList.tail;
	refAddress->next = NULL;
	gc_referenceList.tail->next = refAddress;
	gc_referenceList.size++;
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
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	
	gc_referenceList.size = 0;
}

Reference* generateRef(RefType refType)
{
	Reference* result = NULL;
	
	switch(refType)
	{
		case ReferenceType.BASE:
			break;
	}
	
	if(result != NULL)
		addRef(result);
	
	return result;
}