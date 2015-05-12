#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int a;
    var_push(&a);
   a=0;

   if(true){
      a=1;
      a=2;

   }assert((a == 2));

   return 0;
}
