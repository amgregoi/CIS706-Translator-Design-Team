#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   int i; Array* a = NULL;
   ;var_push(&a);
    Array* b = NULL;
   ;var_push(&b);

   i=0;

   a=New_Array(3); ARRAYGET(a, 0) = New_Integer(1);
   ARRAYGET(a, 1) = New_Integer(2);
   ARRAYGET(a, 2) = New_Integer(3);
   ;

   b=New_Array(3); length = b->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(b, indexX) = New_Integer(0);


   }
   gc_collect();
   ;

   ARRAYGET(b, i)=ARRAYGET(a, i);

   ARRAYGET(b, 2)=New_Integer(5);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
