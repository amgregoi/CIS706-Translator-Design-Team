#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SHeapTree HeapTree;
typedef struct SHeapNode HeapNode;
typedef struct SHeapData HeapData;
HeapTree* hNewHeap();
void* hInsertNode(HeapTree* heapTree, HeapData* data);
void* hDoubleListSize(HeapTree* heapTree);
void* hDeleteMaxNode(HeapTree* heapTree);

NEW_STRUCT (SHeapTree,  Array* list ;
;int capacity;int size;int head;bool isEvenIndex;);

NEW_CONST(HeapTree, 1, ptr, &(ptr->list));

NEW_STRUCT (SHeapNode, int index;int leftChildIndex;int rightChildIndex;int parentIndex;HeapData* data ;
);

NEW_CONST(HeapNode, 1, ptr, &(ptr->data));

NEW_STRUCT (SHeapData, int value;);

 NEW_SIMPLECONST(HeapData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   HeapTree* heapTree = New_HeapTree();var_push(&heapTree);
   HeapData* data = New_HeapData();var_push(&data);
   int i;
   heapTree=hNewHeap();

   for(
   i=0; (i < 20); i++){

      data=New_HeapData();

      data->value=i;
      hInsertNode(heapTree, data);



      }

      gc_collect();
      
   do{
      hDeleteMaxNode(heapTree);


        }while((heapTree->size > 0));

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

HeapTree* hNewHeap(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   HeapTree* newTree = New_HeapTree();var_push(&newTree);

   newTree=New_HeapTree();

   newTree->capacity=10;

   newTree->list=New_Array(newTree->capacity); ;

   newTree->head=1;

   ARRAYGET(newTree->list, 0)=New_HeapNode();

   ((HeapNode*)ARRAYGET(newTree->list, 0))->parentIndex=0;

   newTree->size=1;

   newTree->isEvenIndex=false;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newTree;
}

void* hInsertNode(HeapTree* heapTree, HeapData* data){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 3;
   HeapNode* newNode = New_HeapNode();var_push(&newNode);
   HeapNode* parent = New_HeapNode();var_push(&parent);
   HeapData* swapData = New_HeapData();var_push(&swapData);
   int parentOffset;
   if((heapTree->size >= heapTree->capacity)){
      hDoubleListSize(heapTree);



   }
   newNode=New_HeapNode();

   newNode->index=heapTree->size;

   newNode->leftChildIndex=(2 * newNode->index);

   newNode->rightChildIndex=(newNode->leftChildIndex + 1);

   parentOffset=newNode->index;

   if(!(heapTree->isEvenIndex)){

      parentOffset=(parentOffset - 1);



   }
   if((heapTree->size == 1)){

      newNode->parentIndex=0;



   }else{

      newNode->parentIndex=(parentOffset / 2);



   }
   newNode->data=data;

   ARRAYGET(heapTree->list, heapTree->size)=newNode;
   heapTree->size++;

   heapTree->isEvenIndex=!(heapTree->isEvenIndex);

   if((newNode->parentIndex > 0)){

      parent=ARRAYGET(heapTree->list, newNode->parentIndex);
      while(((newNode->parentIndex > 0) && (newNode->data->value > parent->data->value))){

         swapData=newNode->data;

         newNode->data=parent->data;

         parent->data=swapData;

         newNode=parent;

         parent=ARRAYGET(heapTree->list, newNode->parentIndex);


         }

         gc_collect();
         


   }for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* hDoubleListSize(HeapTree* heapTree){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* newList = NULL;
   ;var_push(&newList);
   int i;
   newList=New_Array((heapTree->capacity * 2)); ;

   heapTree->capacity=(heapTree->capacity * 2);

   for(
   i=0; (i < heapTree->size); i++){

      ARRAYGET(newList, i)=ARRAYGET(heapTree->list, i);



      }

      gc_collect();
      
   heapTree->list=newList;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* hDeleteMaxNode(HeapTree* heapTree){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 5;
   HeapNode* lastElement = New_HeapNode();var_push(&lastElement);
   HeapNode* balanceNode = New_HeapNode();var_push(&balanceNode);
   HeapNode* leftNode = New_HeapNode();var_push(&leftNode);
   HeapNode* rightNode = New_HeapNode();var_push(&rightNode);
   HeapData* swapData = New_HeapData();var_push(&swapData);

   if((heapTree->size == 1)){

      ARRAYGET(heapTree->list, 1)=NULL;

      heapTree->size=0;
      return ;


   }
   lastElement=ARRAYGET(heapTree->list, (heapTree->size - 1));

   ARRAYGET(heapTree->list, (heapTree->size - 1))=NULL;
   heapTree->size--;

   ((HeapNode*)ARRAYGET(heapTree->list, 1))->data=lastElement->data;

   balanceNode=ARRAYGET(heapTree->list, 1);

   leftNode=NULL;

   rightNode=NULL;
   while((balanceNode->leftChildIndex < heapTree->size)){
printf("%d\n", balanceNode->leftChildIndex);
      leftNode=ARRAYGET(heapTree->list, balanceNode->leftChildIndex);

      if((balanceNode->rightChildIndex < heapTree->size)){

         rightNode=ARRAYGET(heapTree->list, balanceNode->rightChildIndex);



      }else{

         rightNode=NULL;



      }
      if((balanceNode->data->value < leftNode->data->value)){

         swapData=balanceNode->data;

         balanceNode->data=leftNode->data;

         leftNode->data=swapData;

         balanceNode=leftNode;



      }else{

         if((balanceNode->data->value < rightNode->data->value)){

            swapData=balanceNode->data;

            balanceNode->data=rightNode->data;

            rightNode->data=swapData;

            balanceNode=rightNode;



         }


      }


printf("rawr\n");
      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
