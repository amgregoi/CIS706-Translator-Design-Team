#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
    int x;
    var_push(&x);
    int y;
    var_push(&y);
    bool b;
    var_push(&b);
   x=1;
   y=2;
   b=((x + y) > 2);
   while(b){
      b=false;
   }
   b=(x > y);
   return ;
   return 0;
}
