#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SObject64 Object64;
Object64* returnObject(Object64* o);

typedef struct SObject64{
}Object64;

void main(){
   Object64* o;o=malloc(sizeof(Object64));
   assert((o == returnObject(o)));

}

Object64* returnObject(Object64* o){
   return o;
}
