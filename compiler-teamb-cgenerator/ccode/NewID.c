#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SNewIDFoo NewIDFoo;

struct SNewIDFoo{
};

int main(){
   NewIDFoo* f;
   NewIDFoo** g;
   NewIDFoo** h;
   f=malloc(sizeof(NewIDFoo));
   g=malloc(sizeof(NewIDFoo*)*4);
   h=malloc(sizeof(NewIDFoo*));
   h=(NewIDFoo*[2]){f, g[0]};

   return 0;
}
