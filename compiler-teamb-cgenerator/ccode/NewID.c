#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SNewIDFoo NewIDFoo;

NEW_STRUCT (SNewIDFoo, NewIDFoo* x ;
NewIDFoo* x2 ;
NewIDFoo* x3 ;
int x4;bool y;);

NEW_CONST(NewIDFoo, 3, ptr, &(ptr->x), &(ptr->x2), &(ptr->x3));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 3;
   NewIDFoo* f = New_NewIDFoo();var_push(&f);
    Array* g = NULL;
   ;var_push(&g);
    Array* h = NULL;
   ;var_push(&h);

   f=New_NewIDFoo();

   g=New_Array(4); ;

   h=New_Array(2); ARRAYGET(h, 0) = f;
   ARRAYGET(h, 1) = ((NewIDFoo*)ARRAYGET(g, 0));
   ;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
