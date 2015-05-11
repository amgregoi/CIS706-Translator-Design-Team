#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int i;
   i=-(1);
   i=(i > 0) ? 2 : 3;
   assert((i == 3));

   return 0;
}
