#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int factorial(int n);

int main(){
   factorial(4);

   return 0;
}

int factorial(int n){
   int result;
   int i;
   assert((n >= 1));
   result=1;
   i=2;
   while((i <= n)){
      result=(result * i);
      i=(i + 1);
   }
   return result;
}
