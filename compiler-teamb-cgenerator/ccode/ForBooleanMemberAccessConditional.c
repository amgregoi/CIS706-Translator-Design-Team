#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SFBMAC FBMAC;

typedef struct SFBMAC{
   bool b;
}FBMAC;

void main(){
   FBMAC* o;
   bool b;
   b = false;
   o = malloc(sizeof(FBMAC));
   o->b = false;

   for(; o->b; ){
      b = true;
   }

   assert((b == false));
}
