#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFBMAC FBMAC;

struct SFBMAC{
   bool b;

};

int main(){
   FBMAC* o;
   bool b;
   b=false;
   o=malloc(sizeof(FBMAC));
   o->b=false;

   for(; o->b; ){
      b=true;
   }
   assert((b == false));

   return 0;
}
