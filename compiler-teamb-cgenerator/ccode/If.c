#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>


int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int a;
   a=0;

   if(true){


   }assert((a == 0));

   a=0;

   if(true){

      a=1;



   }assert((a == 1));

   a=0;

   if(true){

      a=1;

      a=2;



   }assert((a == 2));

   a=0;

   if(true){


   }assert((a == 0));

   a=0;

   if(true){

      a=1;



   }assert((a == 1));

   a=0;

   if(true){

      a=1;



   }else{

      a=2;



   }assert((a == 1));

   a=0;

   if(true){

      a=1;



   }else{

      a=2;

      a=3;



   }assert((a == 1));

   a=0;

   if(false){


   }assert((a == 0));

   a=0;

   if(false){

      a=1;



   }assert((a == 0));

   a=0;

   if(false){

      a=1;



   }assert((a == 0));

   a=0;

   if(false){

      a=1;



   }else{

      a=2;



   }assert((a == 2));

   a=0;

   if(false){

      a=1;



   }else{

      a=2;

      a=3;



   }assert((a == 3));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
