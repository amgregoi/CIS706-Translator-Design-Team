#include <stdlib.h>
#include <stdio.h>
#include "gc.h"

#define ARRAYGET(var, type, i) ((type*)var->address[i])
#define ARRAYSET(var, i) (var->address[i])

typedef struct ssTest{
	Object* obj;
} sTest;

typedef struct sTest{
	Object* obj;
	sTest* tst;
} Test;

sTest* New_sTest()
{
	Object* obj = new_object(0,NULL);
	sTest* newTest = gc_malloc(sizeof(sTest), obj);
	
	return newTest;
}

Test* New_Test()
{
	Test* newTest;
	Object* obj;
	int childNum = 1;
	void** childList = allocate_mem(sizeof(void*) * childNum);
		
	obj = new_object(childNum, childList);
	
	newTest = gc_malloc(sizeof(Test), obj);
	
	newTest->tst = NULL;
	
	childList[0] = &(newTest->tst);
	
	return newTest;
}

void print_var(void* ptr)
{
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("%p ", ptr + i);
	}

	printf("\n");
}

void gc_print()
{
	print_varStack();
	print_refList();
}

void print_header(char header[])
{
	printf("\t\t\t\t\t\t%s\n", header);
	print_gc();
}

void BasicStructTest();
void SelfReferentialTest();
void ArrayTest();
void CyclicReferenceTest();
void BM_MassAlloc();

int main(int argc, char *argv[])
{
	int num = 0;
	
	if(argc > 1) num = atoi(argv[1]);
	
	switch(num)
	{
		case 0:
			printf("Self Referential Test\n");
			SelfReferentialTest();
		break;
		
		case 1:
			printf("Basic Struct Test\n");
			BasicStructTest();
		break;
		
		case 2:
			printf("Array Test\n");
			ArrayTest();
		break;
		
		case 3:
			printf("Cyclic Reference Test\n");
			CyclicReferenceTest();
		break;
		
		case 4:
			printf("Bench Mark: Mass Allocation\n");
			BM_MassAlloc();
		break;
		
		default:
		return 0;
	}
	
	gc_dispose();
	print_header("After Disposal:");
	return 0;
}

void BasicStructTest()
{
	Test* x;
	
	print_header("Initial:");
	
	var_push(1, (void**)&x);
	
	//gc_print(); //This gc_print breaks because print_varStack() can't handle code that hasn't been initialized
	
	x = New_Test();
	x->tst = New_sTest();
	
	print_header("After first allocation:");
	print_header("After Second Allocation:");
	
	gc_collect();
	print_header("After Collection:");
	
	gc_dispose();
	print_header("After Disposal:");
}

typedef struct sToSelf
{
	Object* obj;
	struct sToSelf* self;
} ToSelf;

ToSelf* New_ToSelf()
{
	ToSelf* ptr;
	Object* obj;
	int childNum = 1;
	void** childList = allocate_mem(sizeof(void*) * childNum);
	
	obj = new_object(childNum, childList);
	
	ptr = gc_malloc(sizeof(ToSelf), obj);
	
	ptr->self = NULL;
	
	childList[0] = &(ptr->self);
	
	return ptr;
}

void SelfReferentialTest()
{
	ToSelf* x,*y;
	
	print_header("Initial:");
	
	var_push(1, &x);
	var_push(2, &y);
	
	x = New_ToSelf();
	y = New_ToSelf();
	print_header("After allocating:");
	x->self = y;
	print_header("After assigning y to x->self:");
	y = New_ToSelf();
	x->self->self = y;
	print_header("After assigning y to x->self->self:");
	y = New_ToSelf();
	x = New_ToSelf();
	print_header("After setting clearing variables:");
	gc_collect();
	print_header("After collection:");
	
}

//May need to construct 2 structs to deal with arrays
//One as an array sentinel and another for the objects

typedef struct sData
{
	Object* obj;
	int value;
} Data;

Data* New_Data()
{
	Object* obj = new_object(0, NULL);
	Data* ptr = gc_malloc(sizeof(Data), obj);
	
	return ptr;
}

void print2DArray(Array* arr, int l1, int l2)
{
	int i,j;
	Array* tempArray;
	IntElement* tempElement;

	printf("Printing 2D Array: {\n");
	for(i = 0; i < l1; i++)
	{
		//tempArray = (Array*)arr->address[i];
		printf("\tarr->address[%d] = {", i);
		for(j = 0; j < l2; j++)
		{
			//tempElement = (IntElement*)tempArray->address[j];
			tempElement = ARRAYGET(ARRAYGET(arr, Array, i), IntElement, j);
			printf("%d", tempElement->value);
			if(j < l2-1) printf(", ");
			else printf("}\n");
		}
	}
	printf("}\n");
}

void ArrayTest()
{
	Array* arr;
	Array* arr_2;
	Array* arr_data;
	int n,i,j;

	n = 5;

	var_push(1, &arr);
	var_push(2, &arr_2);

	arr = New_Array(n);
	arr_2 = New_Array(n);

	print_header("Initializing Array:");

	for(i = 0; i < n; i++)
	{
		ARRAYSET(arr, i) = New_Integer(i*i);
		ARRAYSET(arr_2, i) = New_Array(n);
		for(j=0; j < n; j++)
		{
			ARRAYSET(ARRAYGET(arr_2, Array, i), j) = New_Integer(i+j);
			//((Array*)arr_2->address[i])->address[j] = New_Integer(i+j);
		}
	}

	print_header("After Populating Array:");

	printf("Element Values: {");
	
	for(i = 0; i < n; i++)
	{
		printf("%d", ARRAYGET(arr, IntElement, i)->value);
		//printf("%d", ((IntElement*)arr->address[i])->value);
		if(i != n-1)printf(",");
		else printf("}\n");
	}

	print2DArray(arr_2, n, n);
	
	ARRAYSET(arr_2, 2) = arr;
	//arr_2->address[2] = arr;
	
	print_header("After Changing an array:");
	
	print2DArray(arr_2, n, n);
	
	ARRAYSET(arr_2,0) = arr_2;
	//arr_2->address[0] = arr_2;
	
	print_header ("After Creating a Circular Reference:");
	
	var_pop();
	gc_collect();
	
	print_header("After popping arr_2:");
	
	var_pop();
	gc_collect();
	
	print_header("After popping arr:");
	
	var_push(0, &arr_data);
	arr_data = New_Array(n);
	for(i = 0; i < n; i++)
	{
		ARRAYSET(arr_data, i) = New_Data();
		//arr_data->address[i] = New_Data();
	}
	
	print_header("After assigning arr_data:");
	
	var_pop();
	gc_collect();
	
	print_header("After popping arr_data:");
}

typedef struct sTypeB TypeB;
typedef struct sTypeA TypeA;

struct sTypeB
{
	Object* obj;
	TypeA* ref;
};

struct sTypeA
{
	Object* obj;
	TypeB* ref;
};

TypeB* New_TypeB()
{
	int childNum = 1;
	void** childList = allocate_mem(sizeof(void*) * childNum);
	Object* obj = new_object(childNum, childList);
	TypeB* ptr = gc_malloc(sizeof(TypeB), obj);
	
	ptr->ref = NULL;
	
	childList[0] = &(ptr->ref);
	
	return ptr;
}

TypeA* New_TypeA()
{
	int childNum = 1;
	void** childList = allocate_mem(sizeof(void*) * childNum);
	Object* obj = new_object(childNum, childList);
	TypeA* ptr = gc_malloc(sizeof(TypeB), obj);
	
	ptr->ref = NULL;
	
	childList[0] = &(ptr->ref);
	
	return ptr;
}

void CyclicReferenceTest()
{
	TypeA* ta;
	
	var_push(0, &ta);
	
	ta = New_TypeA();
	
	ta->ref = New_TypeB();
	
	ta->ref->ref = New_TypeA();
	
	ta->ref->ref->ref = New_TypeB();
	
	ta->ref->ref->ref->ref = ta;
	
	print_header("After allocating:");
	
	ta->ref = New_TypeB();
	ta->ref->ref = New_TypeA();
	ta->ref->ref->ref = New_TypeB();
	ta->ref->ref->ref->ref = New_TypeA();
	ta->ref->ref->ref->ref->ref = ta->ref->ref->ref;
	
	print_header("After reallocating:");
	
	gc_collect();
	
	print_header("After collection:");
}



void BM_MassAlloc()
{
	Array* arr;
	int n = 5000000, i;
	
	var_push(0, &arr);
	
	arr = New_Array(n);
	
	printf("Allocating %d objects...", n);
	for(i = 0; i < n; i++)
	{
		ARRAYSET(arr, i) = New_Data();
		
		if(ARRAYGET(arr, Data, i) == NULL)
		{
			n = i;
			break;
		}
	}
	printf("Done.\n");
	
	printf("Freeing %d objects...", n);
	var_pop();
	gc_collect();
	printf("Done.\n");
	
}