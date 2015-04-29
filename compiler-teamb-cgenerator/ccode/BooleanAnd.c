#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool and(bool b, bool c);

void main(){
   assert(((true && true) == true));
   assert(((true && false) == false));
   assert(((false && true) == false));
   assert(((false && false) == false));
   assert((and(true, true) == true));
   assert((and(true, false) == false));
   assert((and(false, true) == false));
   assert((and(false, false) == false));

}

bool and(bool b, bool c){
   return (b && c);
}
