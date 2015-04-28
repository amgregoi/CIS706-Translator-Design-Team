#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int multiply(int i, int j);

void main(){
   assert(((2 * 3) == 6));
   assert(((2 * -(3)) == -(6)));
   assert(((-(2) * 3) == -(6)));
   assert(((-(2) * -(3)) == 6));
   assert((multiply(2,3) == 6));
   assert((multiply(2,-(3)) == -(6)));
   assert((multiply(-(2),3) == -(6)));
   assert((multiply(-(2),-(3)) == 6));
}

int multiply(int i, int j){
   return (i * j);
}
