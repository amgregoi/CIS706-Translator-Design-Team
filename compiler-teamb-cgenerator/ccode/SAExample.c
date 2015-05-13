#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* ae(int a, int b);
void* vbe(int a, int b);
void* lv();

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* ae(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int x;int y;
   x=(a + b);

   y=(a * b);
   while((y > (a + b))){

      a=(a + 1);

      x=(a + b);



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* vbe(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int x;int y;
   if((a > b)){

      x=(b - a);

      y=(a - b);



   }else{

      y=(b - a);

      x=(a - b);



   }for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* lv(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int x;int y;int z;
   x=2;

   y=4;

   x=1;

   if((y > x)){

      z=y;



   }else{

      z=(y * y);



   }
   x=z;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
