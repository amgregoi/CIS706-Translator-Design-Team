#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFoo2 Foo2;
typedef struct SBar Bar;

struct SFoo2{
    Bar* b;
    var_push(&b);

};

struct SBar{
    int x;
    var_push(&x);

};

int main(){
    Foo2* a;
    var_push(&a);
   a=New_Foo2();
   a->b=New_Bar();
   a->b->x=5;

   return 0;
}
