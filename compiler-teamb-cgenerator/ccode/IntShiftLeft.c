#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int shiftLeft(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 << 1) == 4));
   assert(((-(2) << 1) == -(4)));
   assert((shiftLeft(2, 1) == 4));
   assert((shiftLeft(-(2), 1) == -(4)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int shiftLeft(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i << j);
}
