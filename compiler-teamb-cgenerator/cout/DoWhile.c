#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int i;
   i = 0;

   do{
      i++;
   }while(i < 10);;

   assert(i == 10);
}
