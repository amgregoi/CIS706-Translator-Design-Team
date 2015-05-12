#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int negate(int i);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((-(2) == -(2)));
   assert((-(+(-(2))) == 2));
   assert((negate(2) == -(2)));
   assert((negate(-(2)) == 2));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int negate(int i){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return -(i);
}
