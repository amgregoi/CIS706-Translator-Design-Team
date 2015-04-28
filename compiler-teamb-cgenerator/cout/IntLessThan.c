#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool lessThan(int i, int j);

void main(){

   assert(2 < 3 == true);

   assert(3 < 2 == false);

   assert(2 < 2 == false);

   assert(
   lessThan(2,3) == true);

   assert(
   lessThan(3,2) == false);

   assert(
   lessThan(2,2) == false);
}

bool lessThan(int i, int j){
   return i < j;
}
