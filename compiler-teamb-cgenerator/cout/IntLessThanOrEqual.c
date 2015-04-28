#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool lessThanOrEqual(int i, int j);

void main(){

   assert(2 <= 3 == true);

   assert(3 <= 2 == false);

   assert(2 <= 2 == true);

   assert(
   lessThanOrEqual(2,3) == true);

   assert(
   lessThanOrEqual(3,2) == false);

   assert(
   lessThanOrEqual(2,2) == true);
}

bool lessThanOrEqual(int i, int j){
   return i <= j;
}
