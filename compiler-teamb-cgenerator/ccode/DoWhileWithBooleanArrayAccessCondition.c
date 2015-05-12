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
   int i;B=New_Array(0); ARRAYGET(B, 0) = New_Boolean(true);
   ARRAYGET(B, 1) = New_Boolean(false);
   ;
   i=1;

   do{
      gc_mark();
      gc_sweep();}while(((BoolElement*)ARRAYGET(B, i))->value);

      print_gc();gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
