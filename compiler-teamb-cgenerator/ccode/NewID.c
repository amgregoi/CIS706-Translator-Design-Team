#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SNewIDFoo NewIDFoo;

struct SNewIDFoo{
};

int main(){
    NewIDFoo* f;
    var_push(&f);
   Array* g;
   Array* h;
   f=New_NewIDFoo();
   g=New_Array(4); ;
   h=New_Array(0); ARRAYSET(h, 0) = f;
   ARRAYSET(h, 1) = g[0];
   ;

   return 0;
}
