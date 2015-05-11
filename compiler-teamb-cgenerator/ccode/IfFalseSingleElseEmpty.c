#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int a;
   a=0;

   if(false){
      a=1;

   }assert((a == 0));

   return 0;
}
