#include <stdlib.h>
#include <stdio.h>
#include "gc.h"

typedef struct sTest{
	Object* obj;
} Test;

Object* TestObject()
{
	int childNum = 0;
	void** childList = NULL;

	/*
	if(childNum > 0)
		childList = malloc(sizeof(void*) * childNum);
	else
		childList = NULL;
	*/

	return new_object(childNum, childList);
}

void print_var(void* ptr)
{
	int i = -8;

	for(i = -8; i < 8; i += 4)
	{
		printf("%p ", ptr + i);
	}

	printf("\n");
}

int main()
{
	Test* x;
	
	printf("&x = %p\n", &x);
	
	var_push(1, (void**)&x);
	x = gc_malloc(sizeof(Test),TestObject());
	print_var(&(x[0]));
	print_varStack();
	print_refList();

	return 0;
}
