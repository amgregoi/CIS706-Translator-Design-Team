#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* multipleIncOrDecOnly();

int main(){
   return 0;
}

void* multipleIncOrDecOnly(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int k;
    var_push(&k);
   i=0;
   j=0;
   k=0;

   for(; ; i++, j++, k++){
   }

}
