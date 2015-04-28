#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int a;
   a = 0;

   if(false){
      a = 1;
   }else{
      a = 2a = 3;
   };

   assert(a == 3);
}
