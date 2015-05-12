#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int a;a=0;

   if(true){
      a=1;

      gc_mark();
      gc_sweep();
   }else{
      a=2;

      gc_mark();
      gc_sweep();
   }print_gc();gc_collect();
   assert((a == 1));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
