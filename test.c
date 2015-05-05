#include <stdlib.h>
#include <stdio.h>
#include "gc.h"

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
	void** childList = malloc(sizeof(void*) * childNum);
		
	obj = new_object(childNum, childList);
	
	newTest = gc_malloc(sizeof(Test), obj);
	
	newTest->tst = NULL;
	
	printf("\t\t&newTest->tst = %p\n", &(newTest->tst));
	printf("\t\tnewTest->tst = %p\n", newTest->tst);
	
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

int main()
{
	//SelfReferentialTest();
	//BasicStructTest();
	ArrayTest();
	
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
	
	x = New_Test();//(Test*)gc_malloc(sizeof(Test), TestObject(1, x));
	x->tst = New_sTest();//(sTest*)gc_malloc(sizeof(sTest), sTestObject());
	
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
	void** childList = malloc(sizeof(void*) * childNum);
	
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

typedef struct sIntElement
{
	Object* obj;
	int value;
} IntElement;

IntElement* New_Integer(int x)
{
	Object* obj = new_object(0,NULL);
	IntElement* ptr = gc_malloc(sizeof(IntElement), obj);
	ptr->value = x;
	return ptr;
}

typedef struct sBoolElement
{
	Object* obj;
	bool value;
} BoolElement;

BoolElement* New_Boolean(bool x)
{
	Object* obj = new_object(0, NULL);
	BoolElement* ptr = gc_malloc(sizeof(BoolElement), obj);
	ptr->value = x;
	return ptr;
}

typedef struct sArray
{
	Object* obj;
	int elemNum;
	void** address;
} Array;

Array* New_Array(int n)
{
	Object* obj;
	Array* ptr;
	void** childList = malloc(sizeof(void*) * n);
	int i;
	
	obj = new_object(n, childList);
	ptr = gc_malloc(sizeof(Array), obj);
	
	ptr->address = malloc(sizeof(void*) * n);
	for(i = 0; i < n; i++)
	{
		ptr->address[i] = NULL;
		childList[i] = &(ptr->address[i]);
	}
	
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
		tempArray = (Array*)arr->address[i];
		printf("\tarr->address[%d] = {", i);
		for(j = 0; j < l2; j++)
		{
			tempElement = (IntElement*)tempArray->address[j];
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
	int n,i,j;

	n = 5;

	var_push(1, &arr);
	var_push(2, &arr_2);

	arr = New_Array(n);
	arr_2 = New_Array(n);

	print_header("Initializing Array:");

	for(i = 0; i < n; i++)
	{
		arr->address[i] = New_Integer(i*i);
		arr_2->address[i] = New_Array(n);
		for(j=0; j < n; j++)
		{
			((Array*)arr_2->address[i])->address[j] = New_Integer(i+j);
		}
	}

	print_header("After Populating Array:");

	printf("Element Values: {");
	
	for(i = 0; i < n; i++)
	{
		printf("%d", ((IntElement*)arr->address[i])->value);
		if(i != n-1)printf(",");
		else printf("}\n");
	}

	print2DArray(arr_2, n, n);
}
