#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* multipleInitAndIncOrDec();

int main(){
   multipleInitAndIncOrDec();

   return 0;
}

void* multipleInitAndIncOrDec(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int k;
    var_push(&k);

   for(i=0, j=0, k=0; (i < 10); i++, j++, k++){
   }
   assert((i == 10));
   assert((j == 10));
   assert((k == 10));

}
