#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool notEqual(int i, int j);

int main(){
   assert(((2 != 3) == true));
   assert(((3 != 2) == true));
   assert(((2 != 2) == false));
   assert((notEqual(2, 3) == true));
   assert((notEqual(3, 2) == true));
   assert((notEqual(2, 2) == false));

   return 0;
}

bool notEqual(int i, int j){
   return (i != j);
}
