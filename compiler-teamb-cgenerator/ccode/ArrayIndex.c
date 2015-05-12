#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int i;
    var_push(&i);
   Array* a;
   Array* b;
   i=0;
   a=New_Array(0); ARRAYSET(a, 0) = 1;
   ARRAYSET(a, 1) = 2;
   ARRAYSET(a, 2) = 3;
   ;
   b=New_Array(3); ;
   b[i]=a[a[i]];
   b[(a[i] * i)]=a[b[a[i]]];

   return 0;
}
