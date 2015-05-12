#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SCWN CWN;

NEW_STRUCT (SCWN, );

 NEW_SIMPLECONST(CWN);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   CWN* o = New_CWN();var_push(&o);
   o=New_CWN();
   o=true ? NULL : o;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
