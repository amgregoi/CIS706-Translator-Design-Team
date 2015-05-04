#pragma once
#include <stdbool.h>
#include <stdlib.h>

#define DEBUG

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

//Constructor prototypes
//can be moved to the .c file as "private" methods
//since they will be used internally
Variable* 	new_variable(int ID, void** addr);
Reference* 	new_reference(void* value);
Object* 	new_object(int childNum, void** childList);

//Method prototypes
void var_push(int ID, void** addr);
void var_pop();
void* gc_malloc(size_t size, Object* obj);
void gc_mark();
void gc_sweep();
void gc_dispose();
void gc_collect();

//Can be moved to the .c file as "private" methods
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

#ifdef DEBUG
	#include <stdio.h>
	void print_object(int tabNum, Object* obj);
	void print_reference(int tabNum, Reference* ref);
	void print_variable(int tabNum, Variable* var);
	void print_tabs(int tabNum);
	void print_array(int size, void** array);

	//Global so there's no need for parameters
	void print_refList();
	void print_varStack();
	void print_freeList();
	void print_gc();
#endif

//Struct Definitions
struct sStack
{
	int size;
	Variable* head;
};

struct sVariable
{
	int ID;
	void** address;
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

