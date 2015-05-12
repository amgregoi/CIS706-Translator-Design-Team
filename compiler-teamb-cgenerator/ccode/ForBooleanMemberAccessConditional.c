#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFBMAC FBMAC;

NEW_STRUCT (SFBMAC, bool b;);

 NEW_SIMPLECONST(FBMAC);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   FBMAC* o = New_FBMAC();var_push(&o);
   bool b;b=false;
   o=New_FBMAC();
   o->b=false;

   for(; o->b; ){
      b=true;

      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      assert((b == false));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
