#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int plus(int i);

int main(){
   assert((+(2) == 2));
   assert((+(-(2)) == -(2)));
   assert((plus(2) == 2));
   assert((plus(-(2)) == -(2)));

   return 0;
}

int plus(int i){
   return +(i);
}
