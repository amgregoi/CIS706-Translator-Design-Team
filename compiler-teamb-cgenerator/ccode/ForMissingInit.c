#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* missingInit();

int main(){
   missingInit();

   return 0;
}

void* missingInit(){
   int i;
   i=0;

   for(; (i < 10); i++){
   }
   assert((i == 10));

}
