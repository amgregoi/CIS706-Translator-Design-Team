#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int remainder(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 % 3) == 2));
   assert(((2 % -(3)) == 2));
   assert(((-(2) % 3) == -(2)));
   assert(((-(2) % -(3)) == -(2)));
   assert(((3 % 2) == 1));
   assert(((3 % -(2)) == 1));
   assert(((-(3) % 2) == -(1)));
   assert(((-(3) % -(2)) == -(1)));
   assert((remainder(2, 3) == 2));
   assert((remainder(2, -(3)) == 2));
   assert((remainder(-(2), 3) == -(2)));
   assert((remainder(-(2), -(3)) == -(2)));
   assert((remainder(3, 2) == 1));
   assert((remainder(3, -(2)) == 1));
   assert((remainder(-(3), 2) == -(1)));
   assert((remainder(-(3), -(2)) == -(1)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int remainder(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i % j);
}
