#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void* missingInit();

void main(){
   missingInit();

}

void* missingInit(){
   int i;i=0;

   for(; (i < 10); i++){
   }
   assert((i == 10));

}
