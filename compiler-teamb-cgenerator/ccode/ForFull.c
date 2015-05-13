#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* full();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   full();


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* full(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(
   i=0; (i < 10); i++){


      }

      gc_collect();
      assert((i == 10));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
