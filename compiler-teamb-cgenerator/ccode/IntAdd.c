#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int add(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 + 3) == 5));
   assert(((2 + -(3)) == -(1)));
   assert(((-(2) + 3) == 1));
   assert(((-(2) + -(3)) == -(5)));
   assert((add(2, 3) == 5));
   assert((add(2, -(3)) == -(1)));
   assert((add(-(2), 3) == 1));
   assert((add(-(2), -(3)) == -(5)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int add(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i + j);
}
