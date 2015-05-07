#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int remainder(int i, int j);

int main(){
   assert(((2 % 3) == 2));
   assert(((2 % -(3)) == 2));
   assert(((-(2) % 3) == -(2)));
   assert(((-(2) % -(3)) == -(2)));
   assert(((3 % 2) == 1));
   assert(((3 % -(2)) == 1));
   assert(((-(3) % 2) == -(1)));
   assert(((-(3) % -(2)) == -(1)));
   assert((remainder(2, 3) == 2));
   assert((remainder(2, -(3)) == 2));
   assert((remainder(-(2), 3) == -(2)));
   assert((remainder(-(2), -(3)) == -(2)));
   assert((remainder(3, 2) == 1));
   assert((remainder(3, -(2)) == 1));
   assert((remainder(-(3), 2) == -(1)));
   assert((remainder(-(3), -(2)) == -(1)));

   return 0;
}

int remainder(int i, int j){
   return (i % j);
}
