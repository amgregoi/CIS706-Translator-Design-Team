#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int remainder(int i, int j);

void main(){
   assert(((2 % 3) == 2));
   assert(((2 % -(3)) == 2));
   assert(((-(2) % 3) == -(2)));
   assert(((-(2) % -(3)) == -(2)));
   assert(((3 % 2) == 1));
   assert(((3 % -(2)) == 1));
   assert(((-(3) % 2) == -(1)));
   assert(((-(3) % -(2)) == -(1)));
   assert((remainder(2,3) == 2));
   assert((remainder(2,-(3)) == 2));
   assert((remainder(-(2),3) == -(2)));
   assert((remainder(-(2),-(3)) == -(2)));
   assert((remainder(3,2) == 1));
   assert((remainder(3,-(2)) == 1));
   assert((remainder(-(3),2) == -(1)));
   assert((remainder(-(3),-(2)) == -(1)));
}

int remainder(int i, int j){
   return (i % j);
}
