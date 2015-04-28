#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SNEN NEN;
NEN* returnNull();

typedef struct SNEN{
}NEN;

void main(){
   assert((NULL == returnNull()));
   assert((returnNull() == NULL));
   assert((NULL == NULL));
   assert(!((NULL != returnNull())));
   assert(!((returnNull() != NULL)));
   assert(!((NULL != NULL)));
   assert((NULL == returnNull()));
}

NEN* returnNull(){
   return NULL;
}
