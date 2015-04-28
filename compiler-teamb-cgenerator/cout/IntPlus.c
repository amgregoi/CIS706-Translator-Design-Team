#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int plus(int i);

void main(){

   assert(+(2) == 2);

   assert(+(-(2)) == -(2));

   assert(
   plus(2) == 2);

   assert(
   plus(-(2)) == -(2));
}

int plus(int i){
   return +(i);
}
