#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int power(int m, int n);

void main(){
   power(3, 2);

}

int power(int m, int n){
   int result;int i;assert((n >= 1));
   result=1;
   i=0;
   while((i < n)){
      result=(result * m);
      i=(i + 1);
   }
   return result;
}
