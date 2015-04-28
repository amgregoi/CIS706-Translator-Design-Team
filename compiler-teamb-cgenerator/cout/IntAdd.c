#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int add(int i, int j);

void main(){

   assert(2 + 3 == 5);

   assert(2 + -(3) == -(1));

   assert(-(2) + 3 == 1);

   assert(-(2) + -(3) == -(5));

   assert(
   add(2,3) == 5);

   assert(
   add(2,-(3)) == -(1));

   assert(
   add(-(2),3) == 1);

   assert(
   add(-(2),-(3)) == -(5));
}

int add(int i, int j){
   return i + j;
}
