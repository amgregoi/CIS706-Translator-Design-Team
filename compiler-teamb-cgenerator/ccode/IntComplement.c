#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int complement(int i);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((~(-(5)) == 4));
   assert((~(4) == -(5)));
   assert((complement(-(5)) == 4));
   assert((complement(4) == -(5)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int complement(int i){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ~(i);
}
