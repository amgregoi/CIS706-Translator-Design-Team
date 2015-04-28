#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int shiftLeft(int i, int j);

void main(){

   assert(2 << 1 == 4);

   assert(-(2) << 1 == -(4));

   assert(
   shiftLeft(2,1) == 4);

   assert(
   shiftLeft(-(2),1) == -(4));
}

int shiftLeft(int i, int j){
   return i << j;
}
