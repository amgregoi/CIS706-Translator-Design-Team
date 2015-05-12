#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* multipleInitOnly();

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

void* multipleInitOnly(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   for(i=0, j=0, k=0; ; ){
      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
