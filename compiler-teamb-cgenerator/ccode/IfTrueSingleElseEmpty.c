#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int a;
    var_push(&a);
   a=0;

   if(true){
      a=1;

   }assert((a == 1));

   return 0;
}
