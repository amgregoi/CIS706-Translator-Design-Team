#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void* full();

void main(){
   full();
}

void* full(){
   int i;

   for(i=0; (i < 10); i++){
   }

   assert((i == 10));
}