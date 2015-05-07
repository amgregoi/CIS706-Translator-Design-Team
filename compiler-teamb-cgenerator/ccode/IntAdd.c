#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int add(int i, int j);

int main(){
   assert(((2 + 3) == 5));
   assert(((2 + -(3)) == -(1)));
   assert(((-(2) + 3) == 1));
   assert(((-(2) + -(3)) == -(5)));
   assert((add(2, 3) == 5));
   assert((add(2, -(3)) == -(1)));
   assert((add(-(2), 3) == 1));
   assert((add(-(2), -(3)) == -(5)));

   return 0;
}

int add(int i, int j){
   return (i + j);
}
