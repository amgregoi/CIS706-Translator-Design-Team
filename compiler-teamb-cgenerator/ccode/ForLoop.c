#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int x;
   for(x=0, i=0, j=0; (i < 5); i++, j++){
      x=((x + i) + j);

      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
