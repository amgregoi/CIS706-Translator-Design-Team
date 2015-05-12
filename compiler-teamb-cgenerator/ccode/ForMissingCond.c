#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* missingCond();

int main(){
   return 0;
}

void* missingCond(){
    int i;
    var_push(&i);

   for(i=0; ; i++){
   }

}
