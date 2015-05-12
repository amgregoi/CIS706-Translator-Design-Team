#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* ae(int a, int b);
void* vbe(int a, int b);
void* lv();

int main(){
   return 0;
}

void* ae(int a, int b){
    int x;
    var_push(&x);
    int y;
    var_push(&y);
   x=(a + b);
   y=(a * b);
   while((y > (a + b))){
      a=(a + 1);
      x=(a + b);
   }

}

void* vbe(int a, int b){
    int x;
    var_push(&x);
    int y;
    var_push(&y);

   if((a > b)){
      x=(b - a);
      y=(a - b);

   }else{
      y=(b - a);
      x=(a - b);

   }
}

void* lv(){
    int x;
    var_push(&x);
    int y;
    var_push(&y);
    int z;
    var_push(&z);
   x=2;
   y=4;
   x=1;

   if((y > x)){
      z=y;

   }else{
      z=(y * y);

   }x=z;

}
