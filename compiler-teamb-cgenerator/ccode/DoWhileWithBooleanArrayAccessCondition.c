#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* B;
    int i;
    var_push(&i);
   B=New_Array(0); ARRAYSET(B, 0) = true;
   ARRAYSET(B, 1) = false;
   ;
   i=1;

   do{
   }while(B[i]);

   return 0;
}
