#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* takeIntArray(Array* I);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   takeIntArray(NULL);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* takeIntArray(Array* I){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
