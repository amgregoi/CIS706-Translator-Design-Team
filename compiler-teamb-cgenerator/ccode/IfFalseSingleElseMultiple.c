#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int a;
   a=0;

   if(false){
      a=1;

   }else{
      a=2;
      a=3;

   }assert((a == 3));

   return 0;
}
