#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int subtract(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int x;assert(((2 - 3) == -(1)));
   assert(((2 - -(3)) == 5));
   assert(((-(2) - 3) == -(5)));
   assert(((-(2) - -(3)) == 1));
   assert((subtract(2, 3) == -(1)));
   assert((subtract(2, -(3)) == 5));
   assert((subtract(-(2), 3) == -(5)));
   assert((subtract(-(2), -(3)) == 1));

   if(((2 - 3) < (5 - (2 + 3)))){

      x=5;



   }
   x=2;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int subtract(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i - j);
}
