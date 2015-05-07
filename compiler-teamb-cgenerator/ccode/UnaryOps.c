#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int unaryPlus(int i);
int unaryMinus(int i);
bool not(bool b);
int complement(int i);

int main(){
   assert((unaryPlus(2) == 2));
   assert((unaryPlus(-(2)) == -(2)));
   assert((unaryMinus(2) == -(2)));
   assert((unaryMinus(-(2)) == 2));
   assert(true);
   assert(!(false));
   assert((not(true) == false));
   assert((not(false) == true));
   assert((complement(-(5)) == 4));

   return 0;
}

int unaryPlus(int i){
   return +(i);
}

int unaryMinus(int i){
   return -(i);
}

bool not(bool b){
   return !(b);
}

int complement(int i){
   return ~(i);
}
