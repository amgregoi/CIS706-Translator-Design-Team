#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int x;
    var_push(&x);

   for(x=0, i=0, j=0; (i < 5); i++, j++){
      x=((x + i) + j);
   }

   return 0;
}
