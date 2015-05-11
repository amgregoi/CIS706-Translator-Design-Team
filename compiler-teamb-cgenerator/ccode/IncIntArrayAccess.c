#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int* I;
   I=malloc(sizeof(int)*1);
   I[0]=1;
   I[0]++;

   return 0;
}
