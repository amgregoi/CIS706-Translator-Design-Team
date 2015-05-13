#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SANTO ANTO;

NEW_STRUCT (SANTO, );

 NEW_SIMPLECONST(ANTO);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ANTO* o = New_ANTO();var_push(&o);

   o=NULL;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
