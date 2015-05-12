#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int a;
    var_push(&a);
   a=0;

   if(false){
   }assert((a == 0));

   return 0;
}
