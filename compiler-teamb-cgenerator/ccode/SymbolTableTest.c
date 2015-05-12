#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SA A;
typedef struct SB B;

struct SA{
    int x;
    var_push(&x);

};

struct SB{
    int x;
    var_push(&x);

};

int main(){
    A* a;
    var_push(&a);
    B* b;
    var_push(&b);
    int z;
    var_push(&z);
   a=New_A();
   b=New_B();
   z=(a->x + b->x);

   return 0;
}
