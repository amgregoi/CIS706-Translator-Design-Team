#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* B;
    bool b;
    var_push(&b);
   b=false;
   B=New_Array(1); ;
   B[0]=false;

   for(; B[0]; ){
      b=true;
   }
   assert((b == false));

   return 0;
}
