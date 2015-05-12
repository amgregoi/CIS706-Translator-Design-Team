#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int* returnIntArray();

int main(){
   Array* i;
   i=returnIntArray();

   return 0;
}

int* returnIntArray(){
   return NULL;
}
