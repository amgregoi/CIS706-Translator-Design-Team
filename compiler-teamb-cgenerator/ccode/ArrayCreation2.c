#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* a;
    int b;
    var_push(&b);
    int i;
    var_push(&i);
   a=New_Array(5); ;
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

   return 0;
}
