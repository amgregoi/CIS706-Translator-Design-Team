#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
   i=0;

   do{
      i++;
   }while((i < 10));
   assert((i == 10));

   return 0;
}
