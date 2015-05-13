#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SArrayManager ArrayManager;
typedef struct SArrayManagerData ArrayManagerData;
ArrayManager* amNewArrayManager(int size);
void* amInsertValue(ArrayManager* array, int index, ArrayManagerData* data);
void* amRemoveValue(ArrayManager* array, int index);
ArrayManagerData* amGetValue(ArrayManager* array, int index);
ArrayManagerData* amPullValue(ArrayManager* array, int index);

NEW_STRUCT (SArrayManager,  Array* array ;
;int length;);

NEW_CONST(ArrayManager, 1, ptr, &(ptr->array));

NEW_STRUCT (SArrayManagerData, int value;);

 NEW_SIMPLECONST(ArrayManagerData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   ArrayManager* arrayManager = New_ArrayManager();var_push(&arrayManager);
   ArrayManagerData* data = New_ArrayManagerData();var_push(&data);
   int i;
   arrayManager=amNewArrayManager(15);

   for(
   i=0; (i < 15); i++){

      data=New_ArrayManagerData();

      data->value=(i * 15);
      amInsertValue(arrayManager, i, data);



      }

      gc_collect();
      
   for(
   i=0; (i < 15); i++){

      data=amGetValue(arrayManager, i);



      }

      gc_collect();
      
   for(
   i=0; (i < 15); i++){

      if((i <= 7)){

         data=amPullValue(arrayManager, i);



      }else{
         amRemoveValue(arrayManager, i);



      }


      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

ArrayManager* amNewArrayManager(int size){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ArrayManager* arrayManager = New_ArrayManager();var_push(&arrayManager);

   arrayManager=New_ArrayManager();

   arrayManager->array=New_Array(size); ;

   arrayManager->length=size;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return arrayManager;
}

void* amInsertValue(ArrayManager* array, int index, ArrayManagerData* data){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   ARRAYGET(array->array, index)=data;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* amRemoveValue(ArrayManager* array, int index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   ARRAYGET(array->array, index)=NULL;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

ArrayManagerData* amGetValue(ArrayManager* array, int index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((ArrayManagerData*)ARRAYGET(array->array, index));
}

ArrayManagerData* amPullValue(ArrayManager* array, int index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ArrayManagerData* data = New_ArrayManagerData();var_push(&data);

   data=amGetValue(array, index);
   amRemoveValue(array, index);
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return data;
}
