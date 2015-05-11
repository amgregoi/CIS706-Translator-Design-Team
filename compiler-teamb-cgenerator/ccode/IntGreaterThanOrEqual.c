#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool greaterThanOrEqual(int i, int j);

int main(){
   assert(((2 >= 3) == false));
   assert(((3 >= 2) == true));
   assert(((2 >= 2) == true));
   assert((greaterThanOrEqual(2, 3) == false));
   assert((greaterThanOrEqual(3, 2) == true));
   assert((greaterThanOrEqual(2, 2) == true));

   return 0;
}

bool greaterThanOrEqual(int i, int j){
   return (i >= j);
}
