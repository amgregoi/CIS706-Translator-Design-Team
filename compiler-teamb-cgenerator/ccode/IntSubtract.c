#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int subtract(int i, int j);

void main(){
   int x;
   assert(((2 - 3) == -(1)));
   assert(((2 - -(3)) == 5));
   assert(((-(2) - 3) == -(5)));
   assert(((-(2) - -(3)) == 1));
   assert((subtract(2,3) == -(1)));
   assert((subtract(2,-(3)) == 5));
   assert((subtract(-(2),3) == -(5)));
   assert((subtract(-(2),-(3)) == 1));

   if(((2 - 3) < (5 - (2 + 3)))){
      x = 5;;
   }
   x = 2;
}

int subtract(int i, int j){
   return (i - j);
}
