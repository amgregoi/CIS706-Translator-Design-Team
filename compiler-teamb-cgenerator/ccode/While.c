#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
   i=0;
   while((i < 10)){
      i++;
   }
   assert((i == 10));

   return 0;
}
