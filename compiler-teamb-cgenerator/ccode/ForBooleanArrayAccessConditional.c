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
   bool b;
   b=false;

   B=New_Array(1); length = B->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(B, indexX) = New_Boolean(false);


   }
   gc_collect();
   ;

   ARRAYGET(B, 0)=New_Boolean(false);

   for(; ((BoolElement*)ARRAYGET(B, 0))->value; ){

      b=true;



      }

      gc_collect();
      assert((b == false));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
