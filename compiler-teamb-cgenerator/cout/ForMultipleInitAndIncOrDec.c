#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void* multipleInitAndIncOrDec();

void main(){

   multipleInitAndIncOrDec();
}

void* multipleInitAndIncOrDec(){
   int i;
   int j;
   int k;

   for(i=0,j=0,k=0; i < 10; i++,j++,k++){
   ;
   }
   ;

   assert(i == 10);

   assert(j == 10);

   assert(k == 10);
}
