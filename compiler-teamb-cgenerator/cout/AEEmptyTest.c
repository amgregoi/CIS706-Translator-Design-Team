#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int x;
   int y;
   bool b;
   x = 1;
   y = 2;
   b = x + y > 2;
   while(b){
      b = false;
   }
   ;
   b = x > y;
   return ;
}
