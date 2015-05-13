#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

Array* returnIntArray();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* i = NULL;
   ;var_push(&i);

   i=returnIntArray();


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

Array* returnIntArray(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return NULL;
}
