#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool notEqual(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 != 3) == true));
   assert(((3 != 2) == true));
   assert(((2 != 2) == false));
   assert((notEqual(2, 3) == true));
   assert((notEqual(3, 2) == true));
   assert((notEqual(2, 2) == false));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

bool notEqual(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i != j);
}
