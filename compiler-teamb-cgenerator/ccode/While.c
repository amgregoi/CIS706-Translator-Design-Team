#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


int main(){
   int i;
   i=0;
   while((i < 10)){
      i++;
   }
   assert((i == 10));

   return 0;
}
