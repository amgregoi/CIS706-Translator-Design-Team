class Deck
{
	public Card[] cards;
	public int size;
	public int capacity;
	public int top;
}

class Card
{
	public int value;
	public int suit;
	public boolean isFaceUp;
}

class Hand
{
	public Card[] cards;
	public int size;
	public int capacity;
	public int value;
}

public class myCardDeck {

	public static void main(String[] args) {
		Deck deck;
		Hand opponent;
		Hand player;
		int i;
		
		deck = dNewDeck(52);
		opponent = dNewHand(5);
		player = dNewHand(5);
		
		for(i = 0; i < 5; i++)
		{
			dDealCard(deck, player);
			dDealCard(deck, opponent);
		}
		
		opponent.value = dGetHandValue(opponent);
		player.value = dGetHandValue(player);
		
		for(i = 0; i < 5; i++)
		{
			dPutCardOnTop(deck, dGetCardFromHand(player, i));
			dPutCardOnTop(deck, dGetCardFromHand(opponent, i));
		}
		
	}
	
	static Deck dNewDeck(int size)
	{
		Deck newDeck;
		Card newCard;
		int i;
		int j;
		
		newDeck = new Deck();
		newDeck.cards = new Card[size];
		newDeck.size = size;
		newDeck.capacity = size;
		newDeck.top = 0;
		
		for(i = 0, j=0; i < size; i++,j++)
		{
			if(j > 3){
				j = 0;
			}
			newCard = new Card();
			newCard.value = i;
			newCard.suit = j;
			newCard.isFaceUp = false;
			newDeck.cards[i] = newCard;
		}
		
		return newDeck;
	}

	static Hand dNewHand(int size)
	{
		Hand newHand;
		
		newHand = new Hand();
		newHand.cards = new Card[size];
		newHand.capacity = size;
		newHand.size = 0;
		
		return newHand;
	}
	
	static Card dGetTopCard(Deck deck)
	{
		Card chosenCard;
		
		StaticJavaLib.assertTrue(deck.size > 0);
		
		chosenCard = deck.cards[deck.top];
		
		deck.top++;
		deck.size--;
		
		return chosenCard;
	}
	
	static void dPutCardOnTop(Deck deck, Card card)
	{
		StaticJavaLib.assertTrue(deck.size < deck.capacity);
		
		deck.top--;
		deck.size++;
		
		deck.cards[deck.top] = card;
	}
	
	
	static Card dGetCardFromHand(Hand hand, int index)
	{
		Card chosenCard;
		int i;
		
		StaticJavaLib.assertTrue(hand.size > 0);
		
		chosenCard = hand.cards[index];
		hand.cards[index] = null;

		hand.size--;
		
		return chosenCard;
	}
	
	static void dPutCardIntoHand(Hand hand, Card card)
	{
		int i;
		int temp;
		
		temp = hand.size;
		StaticJavaLib.assertTrue(hand.size < hand.capacity);
		
		for(i = 0; i < hand.capacity; i++)
		{
			if(hand.cards[i] == null)
			{
				hand.cards[i] = card;
				hand.size++;
				return;
			}
		}
	}
	
	static int dGetHandValue(Hand hand)
	{
		int i;
		int total;
		Card card;
		
		for(i = 0, total = 0; i < hand.size; i++)
		{
			card = hand.cards[i];
			total = total + (card.value * card.suit);
		}
		
		return total;
	}
	
	static void dDealCard(Deck deck, Hand hand)
	{
		Card topCard;
		StaticJavaLib.assertTrue(deck.size > 0);
		StaticJavaLib.assertTrue(hand.size < hand.capacity);

		dPutCardIntoHand(hand, dGetTopCard(deck));
	}
}
