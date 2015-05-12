#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
   i=2;
   i++;
   assert((i == 3));

   return 0;
}
