#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool lessThan(int i, int j);

int main(){
   assert(((2 < 3) == true));
   assert(((3 < 2) == false));
   assert(((2 < 2) == false));
   assert((lessThan(2, 3) == true));
   assert((lessThan(3, 2) == false));
   assert((lessThan(2, 2) == false));

   return 0;
}

bool lessThan(int i, int j){
   return (i < j);
}
