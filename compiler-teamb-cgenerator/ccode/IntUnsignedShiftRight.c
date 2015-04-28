#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int unsignedShiftRight(int i, int j);

void main(){
   assert((((unsigned)2 >> 1) == 1));
   assert((((unsigned)-(2) >> 1) == 2147483647));
   assert((unsignedShiftRight(2,1) == 1));
   assert((unsignedShiftRight(-(2),1) == 2147483647));
}

int unsignedShiftRight(int i, int j){
   return ((unsigned)i >> j);
}
