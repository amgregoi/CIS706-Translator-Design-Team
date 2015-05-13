#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* a = NULL;
   ;var_push(&a);
   int b;int i;
   a=New_Array(5); length = a->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(a, indexX) = New_Integer(0);


   }
   gc_collect();
   ;

   b=0;

   for(
   i=0; (i < 5); i++){

      ARRAYGET(a, i)=New_Integer(i);

      b=(b + ((IntElement*)ARRAYGET(a, i))->value);



      }

      gc_collect();
      assert((b == 10));

   for(
   i=0; (i < 5); i++){
      ((IntElement*)ARRAYGET(a, i))->value++;



      }

      gc_collect();
      
   i=0;

   for(
   i=0; (i < 5); i++){
      assert((((IntElement*)ARRAYGET(a, i))->value == (i + 1)));



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
