#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SCWN CWN;

struct SCWN{
};

int main(){
    CWN* o;
    var_push(&o);
   o=New_CWN();
   o=true ? NULL : o;

   return 0;
}
