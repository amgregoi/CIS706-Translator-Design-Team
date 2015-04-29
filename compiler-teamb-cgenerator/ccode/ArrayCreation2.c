#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int* a;int b;int i;a=malloc(sizeof(int)*5);
   b=0;

   for(i=0; (i < 5); i++){
      a[i]=i;
      b=(b + a[i]);
   }
   assert((b == 10));

   for(i=0; (i < 5); i++){
      a[i]++;
   }
   i=0;

   for(i=0; (i < 5); i++){
      assert((a[i] == (i + 1)));
   }

}
