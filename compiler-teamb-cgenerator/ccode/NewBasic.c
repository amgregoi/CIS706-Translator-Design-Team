#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int* i;
   int* j;
   bool* b;
   bool* c;
   i=malloc(sizeof(int)*4);
   j=(int[3]){1, 2, 3};
   b=malloc(sizeof(bool)*4);
   c=(bool[2]){true, false};

   return 0;
}
