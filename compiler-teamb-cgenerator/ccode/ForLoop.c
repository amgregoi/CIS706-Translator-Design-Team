#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int i;int j;int x;
   for(x=0, i=0, j=0; (i < 5); i++, j++){
      x=((x + i) + j);
   }

}