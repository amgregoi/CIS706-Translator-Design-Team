#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool not(bool b);

void main(){
   assert((!(false) == true));
   assert((!(true) == false));
   assert((not(false) == true));
   assert((not(true) == false));
}

bool not(bool b){
   return !(b);
}
