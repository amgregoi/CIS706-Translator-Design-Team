#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* missingIncOrDec();

int main(){
   return 0;
}

void* missingIncOrDec(){
    int i;
    var_push(&i);

   for(i=0; (i < 10); ){
   }

}
