#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


int main(){
   int i;
   int j;
   int x;

   for(x=0, i=0, j=0; (i < 5); i++, j++){
      x=((x + i) + j);
   }

   return 0;
}
