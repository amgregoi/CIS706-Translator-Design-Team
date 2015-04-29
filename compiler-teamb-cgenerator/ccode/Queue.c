#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SData Data;
typedef struct SLinkedNode LinkedNode;
typedef struct SLinkedList LinkedList;
LinkedList* llNewLinkedList();
bool llIsEmpty(LinkedList* ll);
void* llAddLast(LinkedList* ll, Data* data);
Data* llRemoveFirst(LinkedList* ll);

typedef struct SData{
   int i;
}Data;

typedef struct SLinkedNode{
   Data* data;
   LinkedNode* next;
}LinkedNode;

typedef struct SLinkedList{
   LinkedNode* head;
   LinkedNode* last;
   int size;
}LinkedList;

void main(){
   LinkedList* ll;Data* d;int i;ll=llNewLinkedList();

   for(i=0; (i < 10); i++){
      d=malloc(sizeof(Data));
      d->i=(i + 1);
      llAddLast(ll, d);
   }
   while(!(llIsEmpty(ll))){
      d=llRemoveFirst(ll);
   }

}

LinkedList* llNewLinkedList(){
   LinkedList* result;result=malloc(sizeof(LinkedList));
   result->head=malloc(sizeof(LinkedNode));
   result->last=result->head;
   return result;
}

bool llIsEmpty(LinkedList* ll){
   assert((ll != NULL));
   return (ll->size == 0);
}

void* llAddLast(LinkedList* ll, Data* data){
   assert(((ll != NULL) && (data != NULL)));
   ll->last->next=malloc(sizeof(LinkedNode));
   ll->last=ll->last->next;
   ll->last->data=data;
   ll->size++;

}

Data* llRemoveFirst(LinkedList* ll){
   Data* result;int i;i=0;
   assert((ll->size > 0));
   result=ll->head->next->data;
   ll->head=ll->head->next;
   ll->size--;

   do{
      i++;
      i++;
      i--;
   }while((i < 10));
   return result;
}
