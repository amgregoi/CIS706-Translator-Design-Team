#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SObject64 Object64;
Object64* returnObject(Object64* o);

struct SObject64{
};

int main(){
    Object64* o;
    var_push(&o);
   o=New_Object64();
   assert((o == returnObject(o)));

   return 0;
}

Object64* returnObject(Object64* o){
   return o;
}
