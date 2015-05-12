#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int unaryPlus(int i);
int unaryMinus(int i);
bool not(bool b);
int complement(int i);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((unaryPlus(2) == 2));
   assert((unaryPlus(-(2)) == -(2)));
   assert((unaryMinus(2) == -(2)));
   assert((unaryMinus(-(2)) == 2));
   assert(true);
   assert(!(false));
   assert((not(true) == false));
   assert((not(false) == true));
   assert((complement(-(5)) == 4));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int unaryPlus(int i){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return +(i);
}

int unaryMinus(int i){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return -(i);
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
