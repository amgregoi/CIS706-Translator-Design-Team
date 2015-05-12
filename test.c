#include <stdlib.h>
#include <stdio.h>
#include "gc.h"

typedef struct sTest Test;
typedef struct ssTest sTest;
typedef struct sTypeB TypeB;
typedef struct sTypeA TypeA;
typedef struct sToSelf ToSelf;
typedef struct sData Data;

NEW_STRUCT(sData, int value;)
NEW_STRUCT(sToSelf, struct sToSelf* self;)
NEW_STRUCT(sTypeB, TypeA* ref;)
NEW_STRUCT(sTypeA, TypeB* ref;)
NEW_STRUCT(ssTest,)
NEW_STRUCT(sTest, sTest* tst;)

NEW_SIMPLECONST(sTest);
NEW_CONST(Test, 1, ptr, &(ptr->tst))
NEW_CONST(ToSelf, 1, ptr, &(ptr->self));
NEW_SIMPLECONST(Data)
NEW_CONST(TypeB, 1, ptr, &(ptr->ref))
NEW_CONST(TypeA, 1, ptr, &(ptr->ref))

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

	var_push((void**)&x);

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

void SelfReferentialTest()
{
	ToSelf* x,*y;

	print_header("Initial:");

	var_push(&x);
	var_push(&y);

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
			tempElement = ARRAYGET(ARRAYGET(arr, i), j);
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

	var_push(&arr);
	var_push(&arr_2);

	arr = New_Array(n);
	arr_2 = New_Array(n);

	print_header("Initializing Array:");

	for(i = 0; i < n; i++)
	{
		ARRAYGET(arr, i) = New_Integer(i*i);
		ARRAYGET(arr_2, i) = New_Array(n);
		for(j=0; j < n; j++)
		{
			ARRAYGET(ARRAYGET(arr_2, i), j) = New_Integer(i+j);
			//((Array*)arr_2->address[i])->address[j] = New_Integer(i+j);
		}
	}

	print_header("After Populating Array:");

	printf("Element Values: {");
	
	for(i = 0; i < n; i++)
	{
		printf("%d", ((IntElement*)ARRAYGET(arr, i))->value);
		//printf("%d", ((IntElement*)arr->address[i])->value);
		if(i != n-1)printf(",");
		else printf("}\n");
	}

	print2DArray(arr_2, n, n);
	
	ARRAYGET(arr_2, 2) = arr;
	//arr_2->address[2] = arr;
	
	print_header("After Changing an array:");
	
	print2DArray(arr_2, n, n);
	
	ARRAYGET(arr_2,0) = arr_2;
	//arr_2->address[0] = arr_2;
	
	print_header ("After Creating a Circular Reference:");
	
	var_pop();
	gc_collect();
	
	print_header("After popping arr_2:");
	
	var_pop();
	gc_collect();
	
	print_header("After popping arr:");
	
	var_push(&arr_data);
	arr_data = New_Array(n);
	for(i = 0; i < n; i++)
	{
		ARRAYGET(arr_data, i) = New_Data();
		//arr_data->address[i] = New_Data();
	}
	printf("elemNum = %d\n", arr_data->elemNum);
	print_header("After assigning arr_data:");
	
	var_pop();
	gc_collect();
	
	print_header("After popping arr_data:");
}


void CyclicReferenceTest()
{
	TypeA* ta;
	
	var_push(&ta);
	
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
	
	var_push(&arr);
	
	arr = New_Array(n);
	
	printf("Allocating %d objects...", n);
	for(i = 0; i < n; i++)
	{
		ARRAYGET(arr, i) = New_Data();
		
		if(ARRAYGET(arr, i) == NULL)
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
