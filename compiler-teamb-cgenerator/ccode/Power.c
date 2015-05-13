#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int power(int m, int n);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   power(3, 2);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int power(int m, int n){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int result;int i;assert((n >= 1));

   result=1;

   i=0;
   while((i < n)){

      result=(result * m);

      i=(i + 1);



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return result;
}
