#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int shiftRight(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 >> 1) == 1));
   assert(((-(2) >> 1) == -(1)));
   assert((shiftRight(2, 1) == 1));
   assert((shiftRight(-(2), 1) == -(1)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int shiftRight(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i >> j);
}
