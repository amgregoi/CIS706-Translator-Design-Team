#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>

//#define DEBUG
#define DIAGNOSTIC

//#define ARRAYGET(var, type, i) ((type*)var->address[i])

#define ARRAYGET(var, i) (((Array*) var)->address[i])

#define NEW_STRUCT(name, ...)  struct name {Object* obj; __VA_ARGS__};

#define NEW_SIMPLECONST(name) name* New_ ##name(){\
	Object* obj = new_object(0,NULL); \
	name* newPtr = gc_malloc(sizeof(name), obj); \
	return newPtr;\
}

#define NEW_CONST(name, num_children, ptrName, ...) name* New_ ##name(){ \
	name* ptrName;\
	Object* obj;\
	int childNum = num_children;\
	void** childList = allocate_mem(sizeof(void*) * childNum);\
	obj = new_object(childNum, childList);\
	ptrName = gc_malloc(sizeof(name), obj);\
	init_struct(childList, childNum, __VA_ARGS__);\
	return ptrName;\
}

//This macro is to set a size to allow the free list to grow
//to before freeing everything. This can save time as trying
//to free everything everytime the garbage collector sweeps 
//could be time consuming
#define MAXFREELIST 1

//Struct typedefs and forward declarations
typedef struct sStack 		VarStack;
typedef struct sVariable 	Variable;
typedef struct sRefList 	RefList;
typedef struct sReference 	Reference;
typedef struct sObject 		Object;
typedef struct sIntElement IntElement;
typedef struct sBoolElement BoolElement;
typedef struct sArray Array;

//Constructor prototypes
//can be moved to the .c file as "private" methods
//since they will be used internally
Variable* 	new_variable(void* addr);
Reference* 	new_reference(void* value);
Object* 	new_object(int childNum, void** childList);

//Method prototypes
void var_push(void* addr);
void var_pop();
void* gc_malloc(size_t size, Object* obj);
void gc_mark();
void gc_sweep();
void gc_dispose();
void gc_collect();
void* allocate_mem(size_t size);
IntElement* New_Integer(int x);
BoolElement* New_Boolean(bool x);
Array* New_Array(int n);
void init_struct(void** childList, int count, ...);

//Global so there's no need for parameters
void print_refList();
void print_varStack();
void print_freeList();
void print_gc();
void print_diagnostics();

#ifdef DEBUG
	#include <stdio.h>
	void print_object(int tabNum, Object* obj);
	void print_reference(int tabNum, Reference* ref);
	void print_variable(int tabNum, Variable* var);
	void print_tabs(int tabNum);
	void print_array(int size, void** array);
#endif

//Struct Definitions
struct sStack
{
	int size;
	Variable* head;
};

struct sVariable
{
	void*** address;
	Variable* next;
};

struct sRefList
{
	int size;
	Reference* head;
	Reference* tail;
};

struct sReference
{
	Reference* next;
	Reference* prev;
	Object* value;
};

struct sObject
{
	unsigned char mark;
	int childNum;
	Object** childList;
};


struct sIntElement
{
	Object* obj;
	int value;
};

struct sBoolElement
{
	Object* obj;
	bool value;
};

struct sArray
{
	Object* obj;
	int elemNum;
	void** address;
};
