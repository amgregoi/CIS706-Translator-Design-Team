#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* multipleInitOnly();

int main(){
   return 0;
}

void* multipleInitOnly(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int k;
    var_push(&k);

   for(i=0, j=0, k=0; ; ){
   }

}
