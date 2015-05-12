#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFoo Foo;

NEW_STRUCT (SFoo, );

 NEW_SIMPLECONST(Foo);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   Foo* f = New_Foo();var_push(&f);
    Array* g = NULL;
   ;var_push(&g);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
