#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool not(bool b);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((!(false) == true));
   assert((!(true) == false));
   assert((not(false) == true));
   assert((not(true) == false));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

bool not(bool b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return !(b);
}
