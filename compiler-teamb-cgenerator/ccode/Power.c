#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int power(int m, int n);

int main(){
   power(3, 2);

   return 0;
}

int power(int m, int n){
    int result;
    var_push(&result);
    int i;
    var_push(&i);
   assert((n >= 1));
   result=1;
   i=0;
   while((i < n)){
      result=(result * m);
      i=(i + 1);
   }
   return result;
}
