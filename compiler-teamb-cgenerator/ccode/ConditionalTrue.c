#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
   i=1;
   i=(i > 0) ? 2 : 3;
   assert((i == 2));

   return 0;
}
