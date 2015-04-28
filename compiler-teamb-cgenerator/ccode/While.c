#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int i;
   i = 0;
   while((i < 10)){
      i++;
   }

   assert((i == 10));
}
