#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* i_array = NULL;
   ;var_push(&i_array);

   i_array=New_Array(3); ARRAYGET(i_array, 0) = New_Integer(1);
   ARRAYGET(i_array, 1) = New_Integer(2);
   ARRAYGET(i_array, 2) = New_Integer(3);
   ;

   ARRAYGET(i_array, 0)=New_Integer(1);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
