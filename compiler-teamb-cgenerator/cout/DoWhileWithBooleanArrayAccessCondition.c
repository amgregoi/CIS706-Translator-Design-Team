#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   bool* B;
   int i;
   B = malloc(sizeof(bool));
   B = (bool[2]){true, false};
   i = 1;

   do{
   ;
   }while(B[i]);;
}
