#pragma once
#include "gc.h"

typedef enum eObjectType{
	PRIMITIVE,
	REFERENCE
} ObjectType;

typedef struct sObject{
	ObjectType type;
	//Needs union of Object Templates
} Object;

typedef struct sllNode{
	Object value
	struct sllNode* next;
} LLNode;