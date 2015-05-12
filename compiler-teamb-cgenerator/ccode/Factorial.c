#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int factorial(int n);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   factorial(4);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int factorial(int n){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int result;int i;assert((n >= 1));
   result=1;
   i=2;
   while((i <= n)){
      result=(result * i);
      i=(i + 1);

      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return result;
}
