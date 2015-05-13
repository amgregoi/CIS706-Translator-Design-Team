#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct Sbasetype basetype;

NEW_STRUCT (Sbasetype, );

 NEW_SIMPLECONST(basetype);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   basetype* o = New_basetype();var_push(&o);
   int size;int i;
   size=1000000;

   for(
   i=0; (i < size); i++){

      o=New_basetype();



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
