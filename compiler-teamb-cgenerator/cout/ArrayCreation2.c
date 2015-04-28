#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int* a;
   int b;
   int i;
   a = malloc(sizeof(int)*5);
   i = 0;

   assert(true);

   for(i=0; i < 5; i++){

      assert(a[i] == i + 1);
   }
;
}
