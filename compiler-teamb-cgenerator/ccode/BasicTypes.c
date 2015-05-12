#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
    bool b;
    var_push(&b);
   i=0;
   b=true;

   return 0;
}
