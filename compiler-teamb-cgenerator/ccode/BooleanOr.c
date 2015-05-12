#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool or(bool b, bool c);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((true || true) == true));
   assert(((true || false) == true));
   assert(((false || true) == true));
   assert(((false || false) == false));
   assert((or(true, true) == true));
   assert((or(true, false) == true));
   assert((or(false, true) == true));
   assert((or(false, false) == false));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

bool or(bool b, bool c){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (b || c);
}
