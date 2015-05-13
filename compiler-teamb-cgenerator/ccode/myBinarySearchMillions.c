#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SBinarySearchData BinarySearchData;
int BinarySearch(Array* array, int begin, int end, int value);

NEW_STRUCT (SBinarySearchData, int i;);

 NEW_SIMPLECONST(BinarySearchData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
    Array* array = NULL;
   ;var_push(&array);
   BinarySearchData* data = New_BinarySearchData();var_push(&data);
   int size;int i;int result;
   size=1000000;

   array=New_Array(size); ;

   for(
   i=0; (i < size); i++){

      data=New_BinarySearchData();

      data->i=i;

      ARRAYGET(array, i)=data;



      }

      gc_collect();
      
   result=BinarySearch(array, 0, size, (size / 2));
   assert((((BinarySearchData*)ARRAYGET(array, result))->i == (size / 2)));

   result=BinarySearch(array, 0, size, (size / 3));
   assert((((BinarySearchData*)ARRAYGET(array, result))->i == (size / 3)));

   result=BinarySearch(array, 0, size, (size / 4));
   assert((((BinarySearchData*)ARRAYGET(array, result))->i == (size / 4)));

   result=BinarySearch(array, 0, size, ((2 * size) / 3));
   assert((((BinarySearchData*)ARRAYGET(array, result))->i == ((2 * size) / 3)));

   result=BinarySearch(array, 0, size, ((3 * size) / 4));
   assert((((BinarySearchData*)ARRAYGET(array, result))->i == ((3 * size) / 4)));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int BinarySearch(Array* array, int begin, int end, int value){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int index;int comparisonValue;
   index=(((end - begin) / 2) + begin);

   comparisonValue=((BinarySearchData*)ARRAYGET(array, index))->i;

   if((comparisonValue == value)){
      return index;


   }else{

      if(((end - begin) == 1)){
         return -(1);


      }


   }
   if((comparisonValue > value)){
      return BinarySearch(array, begin, (index - 1), value);


   }else{
      return BinarySearch(array, (index + 1), end, value);


   }for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
