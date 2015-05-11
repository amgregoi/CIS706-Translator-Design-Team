#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

bool or(bool b, bool c);

int main(){
   assert(((true || true) == true));
   assert(((true || false) == true));
   assert(((false || true) == true));
   assert(((false || false) == false));
   assert((or(true, true) == true));
   assert((or(true, false) == true));
   assert((or(false, true) == true));
   assert((or(false, false) == false));

   return 0;
}

bool or(bool b, bool c){
   return (b || c);
}
