#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int divide(int i, int j);

void main(){
   assert(((2 / 3) == 0));
   assert(((2 / -(3)) == 0));
   assert(((-(2) / 3) == 0));
   assert(((-(2) / -(3)) == 0));
   assert(((3 / 2) == 1));
   assert(((3 / -(2)) == -(1)));
   assert(((-(3) / 2) == -(1)));
   assert(((-(3) / -(2)) == 1));
   assert((divide(2,3) == 0));
   assert((divide(2,-(3)) == 0));
   assert((divide(-(2),3) == 0));
   assert((divide(-(2),-(3)) == 0));
   assert((divide(3,2) == 1));
   assert((divide(3,-(2)) == -(1)));
   assert((divide(-(3),2) == -(1)));
   assert((divide(-(3),-(2)) == 1));
}

int divide(int i, int j){
   return (i / j);
}
