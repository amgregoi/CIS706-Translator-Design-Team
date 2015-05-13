#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* initOnly();

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

void* initOnly(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(
   i=0; ; ){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
