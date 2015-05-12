#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SNEN NEN;
NEN* returnNull();

NEW_STRUCT (SNEN, );

 NEW_SIMPLECONST(NEN);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((NULL == returnNull()));
   assert((returnNull() == NULL));
   assert((NULL == NULL));
   assert(!((NULL != returnNull())));
   assert(!((returnNull() != NULL)));
   assert(!((NULL != NULL)));
   assert((NULL == returnNull()));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

NEN* returnNull(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return NULL;
}
