#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* condOnly();

int main(){
   return 0;
}

void* condOnly(){
    int i;
    var_push(&i);
   i=0;

   for(; (i < 10); ){
   }

}
