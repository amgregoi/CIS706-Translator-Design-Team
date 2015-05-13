#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* I = NULL;
   ;var_push(&I);

   I=New_Array(1); length = I->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(I, indexX) = New_Integer(0);


   }
   gc_collect();
   ;

   ARRAYGET(I, 0)=New_Integer(1);
   ((IntElement*)ARRAYGET(I, 0))->value++;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
