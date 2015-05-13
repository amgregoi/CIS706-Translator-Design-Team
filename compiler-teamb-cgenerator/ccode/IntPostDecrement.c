#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   i=2;
   i--;
   assert((i == 1));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
