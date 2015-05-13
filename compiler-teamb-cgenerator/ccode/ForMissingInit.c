#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* missingInit();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   missingInit();


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* missingInit(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   i=0;

   for(; (i < 10); i++){


      }

      gc_collect();
      assert((i == 10));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
