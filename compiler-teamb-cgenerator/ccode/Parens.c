#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
   Array* a;
   i=2;
   i=2;
   j=i;
   i=(i + 0);
   assert((i == 2));
   i=(i * (i + 0));
   assert((i == 4));
   i=((i / 2) - 0);
   assert((i == 2));
   a=New_Array(4); ;

   return 0;
}
