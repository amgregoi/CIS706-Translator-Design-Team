#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int shiftRight(int i, int j);

int main(){
   assert(((2 >> 1) == 1));
   assert(((-(2) >> 1) == -(1)));
   assert((shiftRight(2, 1) == 1));
   assert((shiftRight(-(2), 1) == -(1)));

   return 0;
}

int shiftRight(int i, int j){
   return (i >> j);
}
