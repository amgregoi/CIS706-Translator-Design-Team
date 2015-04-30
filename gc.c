#include "gc.h"
#include <stdbool.h>
#include <stdlib.h>

struct sObject{
	bool mark;
	ObjectType type; //may be unnecessary
	void* pointer;
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
VarStack gc_variableStack;
RefList gc_referenceList;
bool currentMark;

//Methods
void gc_malloc(size_t);
void gc_free(void *);
void pushVar(ObjectType, ValueType, void *);
void popVar();
void disposeVars();
void gc_Mark();
void gc_Sweep();
void addRef(Reference*);
void removeRef(Reference*);

int main()
{
	
	return 0;
}

void pushVar(ObjectType objType, ValueType valType, void* varAddress)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	
	newNode->value = varAddress;
	newNode->next = gc_variableStack.head;
	gc_variableStack.head = newNode->next;
}

void popVar()
{
	StackNode* tempNode;
	tempNode = gc_variableStack.head;
	gc_variableStack.head = gc_variableStack.head->next;
	free(tempNode);
}

void disposeVars()
{
	while(gc_variableStack.head != NULL)
	{
		popVar();
	}
}

void gc_Mark()
{
	
}

void gc_Sweep()
{
	
}

void addRef(Reference* refAddress)
{
	
}

void removeRef(Reference* refAddress)
{
	
}