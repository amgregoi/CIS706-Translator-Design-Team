#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool lessThanOrEqual(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 <= 3) == true));
   assert(((3 <= 2) == false));
   assert(((2 <= 2) == true));
   assert((lessThanOrEqual(2, 3) == true));
   assert((lessThanOrEqual(3, 2) == false));
   assert((lessThanOrEqual(2, 2) == true));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

bool lessThanOrEqual(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i <= j);
}
