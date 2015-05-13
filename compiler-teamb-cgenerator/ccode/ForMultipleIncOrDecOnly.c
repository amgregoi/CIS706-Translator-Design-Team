#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* multipleIncOrDecOnly();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* multipleIncOrDecOnly(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   i=0;

   j=0;

   k=0;

   for(; ; i++, j++, k++){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
