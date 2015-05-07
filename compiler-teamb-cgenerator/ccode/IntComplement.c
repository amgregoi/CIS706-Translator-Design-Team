#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int complement(int i);

int main(){
   assert((~(-(5)) == 4));
   assert((~(4) == -(5)));
   assert((complement(-(5)) == 4));
   assert((complement(4) == -(5)));

   return 0;
}

int complement(int i){
   return ~(i);
}
