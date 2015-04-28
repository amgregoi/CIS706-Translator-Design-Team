#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int shiftRight(int i, int j);

void main(){

   assert(2 >> 1 == 1);

   assert(-(2) >> 1 == -(1));

   assert(
   shiftRight(2,1) == 1);

   assert(
   shiftRight(-(2),1) == -(1));
}

int shiftRight(int i, int j){
   return i >> j;
}
