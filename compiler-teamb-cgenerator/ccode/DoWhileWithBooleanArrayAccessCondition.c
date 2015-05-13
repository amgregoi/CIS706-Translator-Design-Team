#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* B = NULL;
   ;var_push(&B);
   int i;
   B=New_Array(2); ARRAYGET(B, 0) = New_Boolean(true);
   ARRAYGET(B, 1) = New_Boolean(false);
   ;

   i=1;

   do{

        }while(((BoolElement*)ARRAYGET(B, i))->value);

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
