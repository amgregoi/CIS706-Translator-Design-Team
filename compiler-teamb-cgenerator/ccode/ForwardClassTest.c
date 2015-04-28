#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SFoo2 Foo2;
typedef struct SBar Bar;

typedef struct SFoo2{
   Bar* b;
}Foo2;

typedef struct SBar{
   int x;
}Bar;

void main(){
   Foo2* a;
   a = malloc(sizeof(Foo2));
   a->b = malloc(sizeof(Bar));
   a->b->x = 5;
}
