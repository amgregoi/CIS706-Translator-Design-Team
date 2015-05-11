#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   bool* B;
   int i;
   B=(bool[2]){true, false};
   i=1;

   do{
   }while(B[i]);

   return 0;
}
