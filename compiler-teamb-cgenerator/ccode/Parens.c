#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int i;
   int j;
   int* a;
   i = 2;
   i = 2;
   j = i;
   i = (i + 0);
   assert((i == 2));
   i = (i * (i + 0));
   assert((i == 4));
   i = ((i / 2) - 0);
   assert((i == 2));
   a = malloc(sizeof(int)*4);
}
