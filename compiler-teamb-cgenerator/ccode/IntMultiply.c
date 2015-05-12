#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int multiply(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 * 3) == 6));
   assert(((2 * -(3)) == -(6)));
   assert(((-(2) * 3) == -(6)));
   assert(((-(2) * -(3)) == 6));
   assert((multiply(2, 3) == 6));
   assert((multiply(2, -(3)) == -(6)));
   assert((multiply(-(2), 3) == -(6)));
   assert((multiply(-(2), -(3)) == 6));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int multiply(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i * j);
}
