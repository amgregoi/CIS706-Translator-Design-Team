#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool equal(int i, int j);

int main(){
   assert(((2 == 3) == false));
   assert(((3 == 2) == false));
   assert(((2 == 2) == true));
   assert((equal(2, 3) == false));
   assert((equal(3, 2) == false));
   assert((equal(2, 2) == true));

   return 0;
}

bool equal(int i, int j){
   return (i == j);
}
