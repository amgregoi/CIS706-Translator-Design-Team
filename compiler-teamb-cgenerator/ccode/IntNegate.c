#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int negate(int i);

void main(){
   assert((-(2) == -(2)));
   assert((-(+(-(2))) == 2));
   assert((negate(2) == -(2)));
   assert((negate(-(2)) == 2));

}

int negate(int i){
   return -(i);
}
