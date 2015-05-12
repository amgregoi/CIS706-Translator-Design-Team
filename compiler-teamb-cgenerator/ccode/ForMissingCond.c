#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* missingCond();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* missingCond(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(i=0; ; i++){
      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
