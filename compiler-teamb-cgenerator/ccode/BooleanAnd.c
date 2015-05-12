#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool and(bool b, bool c);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((true && true) == true));
   assert(((true && false) == false));
   assert(((false && true) == false));
   assert(((false && false) == false));
   assert((and(true, true) == true));
   assert((and(true, false) == false));
   assert((and(false, true) == false));
   assert((and(false, false) == false));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

bool and(bool b, bool c){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (b && c);
}
