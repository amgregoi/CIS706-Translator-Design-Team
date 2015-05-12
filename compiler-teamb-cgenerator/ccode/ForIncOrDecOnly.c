#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* incOrDecOnly();

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

void* incOrDecOnly(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;i=0;

   for(; ; i++){
      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
