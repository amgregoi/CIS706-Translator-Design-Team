#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* multipleInitAndIncOrDec();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   multipleInitAndIncOrDec();


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* multipleInitAndIncOrDec(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   for(
   i=0, 
   j=0, 
   k=0; (i < 10); i++, j++, k++){


      }

      gc_collect();
      assert((i == 10));
   assert((j == 10));
   assert((k == 10));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
