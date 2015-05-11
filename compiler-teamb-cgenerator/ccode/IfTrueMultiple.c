#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int a;
   a=0;

   if(true){
      a=1;
      a=2;

   }assert((a == 2));

   return 0;
}
