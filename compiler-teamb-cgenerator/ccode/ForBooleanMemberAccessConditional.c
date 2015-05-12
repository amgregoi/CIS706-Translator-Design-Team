#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFBMAC FBMAC;

struct SFBMAC{
    bool b;
    var_push(&b);

};

int main(){
    FBMAC* o;
    var_push(&o);
    bool b;
    var_push(&b);
   b=false;
   o=New_FBMAC();
   o->b=false;

   for(; o->b; ){
      b=true;
   }
   assert((b == false));

   return 0;
}
