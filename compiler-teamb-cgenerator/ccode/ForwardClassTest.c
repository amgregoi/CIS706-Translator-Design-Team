#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFoo2 Foo2;
typedef struct SBar Bar;

NEW_STRUCT (SFoo2, Bar* b ;
);

NEW_CONST(Foo2, 1, ptr, &(ptr->b));

NEW_STRUCT (SBar, int x;);

 NEW_SIMPLECONST(Bar);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Foo2* a = New_Foo2();var_push(&a);

   a=New_Foo2();

   a->b=New_Bar();

   a->b->x=5;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
