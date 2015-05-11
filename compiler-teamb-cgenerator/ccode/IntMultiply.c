#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int multiply(int i, int j);

int main(){
   assert(((2 * 3) == 6));
   assert(((2 * -(3)) == -(6)));
   assert(((-(2) * 3) == -(6)));
   assert(((-(2) * -(3)) == 6));
   assert((multiply(2, 3) == 6));
   assert((multiply(2, -(3)) == -(6)));
   assert((multiply(-(2), 3) == -(6)));
   assert((multiply(-(2), -(3)) == 6));

   return 0;
}

int multiply(int i, int j){
   return (i * j);
}
