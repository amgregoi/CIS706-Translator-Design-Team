#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SObject64 Object64;
Object64* returnObject(Object64* o);

struct SObject64{
};

int main(){
   Object64* o;
   o=malloc(sizeof(Object64));
   assert((o == returnObject(o)));

   return 0;
}

Object64* returnObject(Object64* o){
   return o;
}
