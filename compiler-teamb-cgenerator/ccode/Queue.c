#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SData Data;
typedef struct SLinkedNode LinkedNode;
typedef struct SLinkedList LinkedList;
LinkedList* llNewLinkedList();
bool llIsEmpty(LinkedList* ll);
void* llAddLast(LinkedList* ll, Data* data);
Data* llRemoveFirst(LinkedList* ll);

struct SData{
    int i;
    var_push(&i);

};

struct SLinkedNode{
    Data* data;
    var_push(&data);
    LinkedNode* next;
    var_push(&next);

};

struct SLinkedList{
    LinkedNode* head;
    var_push(&head);
    LinkedNode* last;
    var_push(&last);
    int size;
    var_push(&size);

};

int main(){
    LinkedList* ll;
    var_push(&ll);
    Data* d;
    var_push(&d);
    int i;
    var_push(&i);
   ll=llNewLinkedList();

   for(i=0; (i < 10); i++){
      d=New_Data();
      d->i=(i + 1);
      llAddLast(ll, d);
   }
   while(!(llIsEmpty(ll))){
      d=llRemoveFirst(ll);
   }

   return 0;
}

LinkedList* llNewLinkedList(){
    LinkedList* result;
    var_push(&result);
   result=New_LinkedList();
   result->head=New_LinkedNode();
   result->last=result->head;
   return result;
}

bool llIsEmpty(LinkedList* ll){
   assert((ll != NULL));
   return (ll->size == 0);
}

void* llAddLast(LinkedList* ll, Data* data){
   assert(((ll != NULL) && (data != NULL)));
   ll->last->next=New_LinkedNode();
   ll->last=ll->last->next;
   ll->last->data=data;
   ll->size++;

}

Data* llRemoveFirst(LinkedList* ll){
    Data* result;
    var_push(&result);
    int i;
    var_push(&i);
   i=0;
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
