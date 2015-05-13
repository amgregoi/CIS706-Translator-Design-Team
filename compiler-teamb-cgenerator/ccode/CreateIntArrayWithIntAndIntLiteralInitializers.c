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
   int i;
   i=0;

   I=New_Array(2); ARRAYGET(I, 0) = New_Integer(i);
   ARRAYGET(I, 1) = New_Integer(1);
   ;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
