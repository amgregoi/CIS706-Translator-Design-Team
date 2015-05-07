#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


int main(){
   int a;
   a=0;

   if(true){
      a=1;

   }assert((a == 1));

   return 0;
}
