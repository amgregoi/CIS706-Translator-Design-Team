#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SCWN CWN;

struct SCWN{
};

int main(){
   CWN* o;
   o=malloc(sizeof(CWN));
   o=true ? NULL : o;

   return 0;
}
