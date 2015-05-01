#pragma once
#include <stdbool.h>

typedef enum 	eObjectType ObjectType;

//typedef union 	uValueType 	ValueType;

typedef struct 	sObject 	Object;
typedef struct 	sStackNode 	StackNode;
typedef struct	sStack		VarStack;
typedef struct 	sReference 	Reference;
typedef struct	sRefList	RefList;

enum eObjectType{
	PRIMITIVE,
	REFERENCE
};
