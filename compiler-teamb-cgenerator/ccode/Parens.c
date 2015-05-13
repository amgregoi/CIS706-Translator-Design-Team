#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   int i;int j; Array* a = NULL;
   ;var_push(&a);

   i=2;

   i=2;

   j=i;

   i=(i + 0);
   assert((i == 2));

   i=(i * (i + 0));
   assert((i == 4));

   i=((i / 2) - 0);
   assert((i == 2));

   a=New_Array(4); length = a->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(a, indexX) = New_Integer(0);


   }
   gc_collect();
   ;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
