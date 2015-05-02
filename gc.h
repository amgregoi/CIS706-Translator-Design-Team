#pragma once
#include <stdbool.h>

typedef enum 	eObjectType ObjectType;
typedef union 	uValueType 	ValueType;
typedef struct 	sObject 	Object;
typedef struct 	sStackNode 	StackNode;
typedef struct	sStack		VarStack;
typedef struct 	sReference 	Reference;
typedef struct	sRefList	RefList;

typedef union uValueType ValueType;
typedef enum eReferenceType RefType;

bool currentMark = true;

enum eObjectType{
	PRIMITIVE,
	REFERENCE
};

union uValueType{
	int integer;
	bool boolean;
	//Other Class Templates Here
	/**/
};

enum eReferenceType{
	/**/
	BASE
};

Reference* generateRef(RefType refType)
{
	Reference* result = NULL;
	
	switch(refType)
	{
		case BASE:
			break;
	}
	
	return result;
}

struct sObject{
	bool mark;
	void** pointer;
	int numChildren;
	Object** childList;
};

Object* New_Object(void** ptr, int numChildren)
{
	Object* newObj = malloc(sizeof(Object));
	newObj->mark = !currentMark;
	newObj->pointer = ptr;
	newObj->numChildren = numChildren;
	newObj->childList = malloc(sizeof(Object*) * numChildren);
	
	return newObj;
}

struct sStackNode{
	//Object value;
	StackNode* next;
	void * value;
};

StackNode* New_StackNode(StackNode* next, void* value)
{
	StackNode* result = malloc(sizeof(StackNode));
	
	result->next = next;
	result->value = value;
	
	return result;
}

struct sStack{
	int size;
	StackNode* head;
};

struct sReference{
	Reference* next;
	Reference* prev;
	Object value;
};

Reference* New_Reference(Object value)
{
	Reference* result = malloc(sizeof(Reference));
	
	result->next = NULL;
	result->prev = NULL;
	result->value = value;
	
	return result;
}

struct sRefList{
	int size;
	Reference* head;
	Reference* tail;
};

//Global Variables
VarStack gc_variableStack = {0,NULL};
RefList gc_referenceList = {0,NULL,NULL};


//Methods
void* gc_Malloc(RefType);
void gc_Free(void *);
void gc_Mark();
void gc_Sweep();
void gc_Dispose();
void pushVar(ObjectType, void *);
void popVar();
void disposeVars();
void addRef(Reference*);
void removeRef(Reference*);
Reference* getRef(void *);
void disposeRefs();
Reference* generateRef(RefType);