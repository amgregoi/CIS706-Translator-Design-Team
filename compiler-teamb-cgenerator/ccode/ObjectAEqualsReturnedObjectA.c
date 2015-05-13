#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SObject64 Object64;
Object64* returnObject(Object64* o);

NEW_STRUCT (SObject64, );

 NEW_SIMPLECONST(Object64);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Object64* o = New_Object64();var_push(&o);

   o=New_Object64();
   assert((o == returnObject(o)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

Object64* returnObject(Object64* o){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return o;
}
