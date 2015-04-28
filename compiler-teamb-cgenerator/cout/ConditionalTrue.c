#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int i;
   i = 1;
   i = i > 0 ? 2 : 3;

   assert(i == 2);
}
