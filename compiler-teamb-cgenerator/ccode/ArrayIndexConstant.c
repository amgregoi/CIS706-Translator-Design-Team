#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* i_array;
   i_array=New_Array(0); ARRAYSET(i_array, 0) = 1;
   ARRAYSET(i_array, 1) = 2;
   ARRAYSET(i_array, 2) = 3;
   ;
   i_array[0]=1;

   return 0;
}
