#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int a;
   a = 0;

   if(true){
      a = 1;
   }else{
      a = 2;
   };

   assert(a == 1);
}
