#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 4;
    Array* i = NULL;
   ;var_push(&i);
    Array* j = NULL;
   ;var_push(&j);
    Array* b = NULL;
   ;var_push(&b);
    Array* c = NULL;
   ;var_push(&c);
   int x;i=New_Array(4); length = i->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(i, indexX) = New_Integer(0);
   	gc_mark();
   	gc_sweep();
   }
   print_gc();gc_collect();
   ;
   j=New_Array(0); ARRAYGET(j, 0) = New_Integer(1);
   ARRAYGET(j, 1) = New_Integer(2);
   ARRAYGET(j, 2) = New_Integer(3);
   ;
   x=5;
   b=New_Array(4); length = b->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(b, indexX) = New_Boolean(false);
   	gc_mark();
   	gc_sweep();
   }
   print_gc();gc_collect();
   ;
   c=New_Array(0); ARRAYGET(c, 0) = New_Boolean(true);
   ARRAYGET(c, 1) = New_Boolean(false);
   ;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
