#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SNEN NEN;
NEN* returnNull();

struct SNEN{
};

int main(){
   assert((NULL == returnNull()));
   assert((returnNull() == NULL));
   assert((NULL == NULL));
   assert(!((NULL != returnNull())));
   assert(!((returnNull() != NULL)));
   assert(!((NULL != NULL)));
   assert((NULL == returnNull()));

   return 0;
}

NEN* returnNull(){
   return NULL;
}
