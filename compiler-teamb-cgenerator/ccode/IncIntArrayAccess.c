#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* I;
   I=New_Array(1); ;
   I[0]=1;
   I[0]++;

   return 0;
}
