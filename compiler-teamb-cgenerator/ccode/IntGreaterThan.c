#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool greaterThan(int i, int j);

void main(){
   assert(((2 > 3) == false));
   assert(((3 > 2) == true));
   assert(((2 > 2) == false));
   assert((greaterThan(2,3) == false));
   assert((greaterThan(3,2) == true));
   assert((greaterThan(2,2) == false));
}

bool greaterThan(int i, int j){
   return (i > j);
}
