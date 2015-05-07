#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

bool not(bool b);

int main(){
   assert((!(false) == true));
   assert((!(true) == false));
   assert((not(false) == true));
   assert((not(true) == false));

   return 0;
}

bool not(bool b){
   return !(b);
}
