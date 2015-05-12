#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool equal(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((2 == 3) == false));
   assert(((3 == 2) == false));
   assert(((2 == 2) == true));
   assert((equal(2, 3) == false));
   assert((equal(3, 2) == false));
   assert((equal(2, 2) == true));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

bool equal(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i == j);
}
