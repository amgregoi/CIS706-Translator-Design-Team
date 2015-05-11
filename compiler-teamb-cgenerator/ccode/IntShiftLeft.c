#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int shiftLeft(int i, int j);

int main(){
   assert(((2 << 1) == 4));
   assert(((-(2) << 1) == -(4)));
   assert((shiftLeft(2, 1) == 4));
   assert((shiftLeft(-(2), 1) == -(4)));

   return 0;
}

int shiftLeft(int i, int j){
   return (i << j);
}
