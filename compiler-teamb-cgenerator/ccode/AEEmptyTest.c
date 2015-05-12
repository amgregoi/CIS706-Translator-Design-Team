#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int x;int y;bool b;x=1;
   y=2;
   b=((x + y) > 2);
   while(b){
      b=false;

      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      b=(x > y);
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ;

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
