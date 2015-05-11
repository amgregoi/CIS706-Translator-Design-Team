#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int negate(int i);

int main(){
   assert((-(2) == -(2)));
   assert((-(+(-(2))) == 2));
   assert((negate(2) == -(2)));
   assert((negate(-(2)) == 2));

   return 0;
}

int negate(int i){
   return -(i);
}
