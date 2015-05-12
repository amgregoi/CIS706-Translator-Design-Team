#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int unsignedShiftRight(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((((unsigned)2 >> 1) == 1));
   assert((((unsigned)-(2) >> 1) == 2147483647));
   assert((unsignedShiftRight(2, 1) == 1));
   assert((unsignedShiftRight(-(2), 1) == 2147483647));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int unsignedShiftRight(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((unsigned)i >> j);
}
