#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFoo2 Foo2;
typedef struct SBar Bar;

struct SFoo2{
   Bar* b;

};

struct SBar{
   int x;

};

int main(){
   Foo2* a;
   a=malloc(sizeof(Foo2));
   a->b=malloc(sizeof(Bar));
   a->b->x=5;

   return 0;
}
