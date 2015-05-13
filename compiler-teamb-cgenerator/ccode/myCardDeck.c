#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SDeck Deck;
typedef struct SCard Card;
typedef struct SHand Hand;
Deck* dNewDeck(int size);
Hand* dNewHand(int size);
Card* dGetTopCard(Deck* deck);
void* dPutCardOnTop(Deck* deck, Card* card);
Card* dGetCardFromHand(Hand* hand, int index);
void* dPutCardIntoHand(Hand* hand, Card* card);
int dGetHandValue(Hand* hand);
void* dDealCard(Deck* deck, Hand* hand);

NEW_STRUCT (SDeck,  Array* cards ;
;int size;int capacity;int top;);

NEW_CONST(Deck, 1, ptr, &(ptr->cards));

NEW_STRUCT (SCard, int value;int suit;bool isFaceUp;);

 NEW_SIMPLECONST(Card);
NEW_STRUCT (SHand,  Array* cards ;
;int size;int capacity;int value;);

NEW_CONST(Hand, 1, ptr, &(ptr->cards));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 3;
   Deck* deck = New_Deck();var_push(&deck);
   Hand* opponent = New_Hand();var_push(&opponent);
   Hand* player = New_Hand();var_push(&player);
   int i;
   deck=dNewDeck(52);

   opponent=dNewHand(5);

   player=dNewHand(5);

   for(
   i=0; (i < 5); i++){
      dDealCard(deck, player);
      dDealCard(deck, opponent);



      }

      gc_collect();
      
   opponent->value=dGetHandValue(opponent);

   player->value=dGetHandValue(player);

   for(
   i=0; (i < 5); i++){
      dPutCardOnTop(deck, dGetCardFromHand(player, i));
      dPutCardOnTop(deck, dGetCardFromHand(opponent, i));



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

Deck* dNewDeck(int size){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   Deck* newDeck = New_Deck();var_push(&newDeck);
   Card* newCard = New_Card();var_push(&newCard);
   int i;int j;
   newDeck=New_Deck();

   newDeck->cards=New_Array(size); ;

   newDeck->size=size;

   newDeck->capacity=size;

   newDeck->top=0;

   for(
   i=0, 
   j=0; (i < size); i++, j++){

      if((j > 3)){

         j=0;



      }
      newCard=New_Card();

      newCard->value=i;

      newCard->suit=j;

      newCard->isFaceUp=false;

      ARRAYGET(newDeck->cards, i)=newCard;



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newDeck;
}

Hand* dNewHand(int size){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Hand* newHand = New_Hand();var_push(&newHand);

   newHand=New_Hand();

   newHand->cards=New_Array(size); ;

   newHand->capacity=size;

   newHand->size=0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newHand;
}

Card* dGetTopCard(Deck* deck){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Card* chosenCard = New_Card();var_push(&chosenCard);
   assert((deck->size > 0));

   chosenCard=ARRAYGET(deck->cards, deck->top);
   deck->top++;
   deck->size--;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return chosenCard;
}

void* dPutCardOnTop(Deck* deck, Card* card){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((deck->size < deck->capacity));
   deck->top--;
   deck->size++;

   ARRAYGET(deck->cards, deck->top)=card;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

Card* dGetCardFromHand(Hand* hand, int index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Card* chosenCard = New_Card();var_push(&chosenCard);
   int i;assert((hand->size > 0));

   chosenCard=ARRAYGET(hand->cards, index);

   ARRAYGET(hand->cards, index)=NULL;
   hand->size--;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return chosenCard;
}

void* dPutCardIntoHand(Hand* hand, Card* card){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int temp;
   temp=hand->size;
   assert((hand->size < hand->capacity));

   for(
   i=0; (i < hand->capacity); i++){

      if((((Card*)ARRAYGET(hand->cards, i)) == NULL)){

         ARRAYGET(hand->cards, i)=card;
         hand->size++;
         return ;


      }


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

int dGetHandValue(Hand* hand){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   int i;int total;Card* card = New_Card();var_push(&card);

   for(
   i=0, 
   total=0; (i < hand->size); i++){

      card=ARRAYGET(hand->cards, i);

      total=(total + (card->value * card->suit));



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return total;
}

void* dDealCard(Deck* deck, Hand* hand){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Card* topCard = New_Card();var_push(&topCard);
   assert((deck->size > 0));
   assert((hand->size < hand->capacity));
   dPutCardIntoHand(hand, dGetTopCard(deck));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
