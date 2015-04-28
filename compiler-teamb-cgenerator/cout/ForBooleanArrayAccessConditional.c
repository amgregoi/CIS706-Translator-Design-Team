#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   bool* B;
   bool b;
   b = false;
   B = malloc(sizeof(bool)*1);
   B[0] = false;

   for(; B[0]; ){
      b = true;
   }
   ;

   assert(b == false);
}
