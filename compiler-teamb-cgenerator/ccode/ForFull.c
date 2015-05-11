#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* full();

int main(){
   full();

   return 0;
}

void* full(){
   int i;

   for(i=0; (i < 10); i++){
   }
   assert((i == 10));

}
