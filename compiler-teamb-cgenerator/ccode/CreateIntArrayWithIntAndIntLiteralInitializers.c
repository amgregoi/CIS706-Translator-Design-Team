#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* I;
    int i;
    var_push(&i);
   i=0;
   I=New_Array(0); ARRAYSET(I, 0) = i;
   ARRAYSET(I, 1) = 1;
   ;

   return 0;
}
