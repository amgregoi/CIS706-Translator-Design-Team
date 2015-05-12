#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   Array* i;
   Array* j;
   Array* b;
   Array* c;
   i=New_Array(4); ;
   j=New_Array(0); ARRAYSET(j, 0) = 1;
   ARRAYSET(j, 1) = 2;
   ARRAYSET(j, 2) = 3;
   ;
   b=New_Array(4); ;
   c=New_Array(0); ARRAYSET(c, 0) = true;
   ARRAYSET(c, 1) = false;
   ;

   return 0;
}
