#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;i=0;

   do{
      i++;

      gc_mark();
      gc_sweep();}while((i < 10));

      print_gc();gc_collect();
      assert((i == 10));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
