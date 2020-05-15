#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CardType can be a combat type of Attack, Defend, and run or it can be a linked list type of Head or Tail
typedef enum CardType
{
	ATTACK,
	DEFEND,
	RUN,
	HEAD,
	TAIL
} CardType;

//Cards are a combination of a CardType and a number
typedef struct Card_struct
{
	CardType Type;
	int Value;
} Card;

//CardNode combines cards and the next node for linked list utilization
typedef struct CardNode_struct
{
	Card info;
	struct CardNode_struct *next;
} CardNode;

//getRandomNumber returns a random number between parameters min and max inclusive
int generateRandomNumber(int min, int max)
{
	int n;

	n = (rand() % (max - min)) + min;

	return n;
}
//generateType returns a cardType for a combat card, generated at random
CardType generateType()
{
	int randomNumber = generateRandomNumber(1, 10);
	CardType output;
	if (randomNumber > 5)
	{
		output = DEFEND;
	}
	else if (randomNumber > 1)
	{
		output = ATTACK;
	}
	else
	{
		output = RUN;
	}
	return output;
}
//generatevalue returns an value within a range specified by each type of combat card; 
CardType generateValue(CardType Input)
{
	int output;
	if (Input == DEFEND)
	{
		output = generateRandomNumber(3, 8);
	}
	else if (Input == ATTACK)
	{
		output = generateRandomNumber(1, 5);
	}
	else
	{
		output = RUN;
	}
	return output;
}
//constructCard returns a pointer to a CardNode
CardNode *constructCard()
{
	CardNode *newCard;
	newCard = (CardNode *)malloc(sizeof(CardNode));
	CardType tempType = generateType();
	newCard->info.Type = tempType;
	newCard->info.Value = generateValue(tempType);
	return newCard;
}
//insertMiddle recursively iterates through linked list compare, and returns the node in compare that value comes after  
CardNode *insertMiddle(CardNode *compare, int value)
{
	CardNode *output;
	CardNode *nextNode;
	nextNode = compare->next;
	int nextValue;
	nextValue = nextNode->info.Value;
	if (value >= nextValue)
	{
		output = compare;
	}
	else
	{
		output = insertMiddle(compare->next, value);
	}
	return output;
}
//drawCards returns the head node after inserting addSize nodes in descending order
CardNode *drawCards(CardNode *head, int addSize)
{
	CardNode *previous;
	CardNode *next;
	CardNode *newCard;
	int tempValue;
	int i;
	for (i = 0; i < addSize; i++)
	{
		newCard = constructCard();
		tempValue = newCard->info.Value;
		previous = insertMiddle(head, tempValue);
		newCard->next = previous->next;
		if (previous->info.Type == HEAD)
		{
			head->next = newCard;
		}
		else
		{
			previous->next = newCard;
		}
	}
	return head;
}
//constructHead returns the head node after constructing it
CardNode *constructHead()
{
	CardNode *head;
	head = (CardNode *)malloc(sizeof(CardNode));
	head->info.Type = HEAD;
	return head;
}
//constructTail returns the tail node after constructing it
CardNode *constructTail()
{
	CardNode *tail;
	tail = (CardNode *)malloc(sizeof(CardNode));
	tail->info.Type = TAIL;
	tail->info.Value = -1;
	return tail;
}
//seedList returns the head of a linked list after creating a head node and tail node
CardNode *seedList()
{
	CardNode *head;
	head = constructHead();
	CardNode *tail;
	tail = constructTail();
	head->next = tail;
	return head;
}
//constructDeck returns the head node of a linked list after comnbining a linked list seed and new cards
CardNode *constructDeck(int deckSize)
{
	CardNode *head;
	head = seedList();
	head = drawCards(head, deckSize);
	return head;
}
//typeToChar returns a character from a combat card type
char typeToChar(CardType type)
{
	char output;
	if (type == DEFEND)
	{
		output = 'D';
	}
	if (type == ATTACK)
	{
		output = 'A';
	}
	if (type == RUN)
	{
		output = 'R';
	}
	return output;
}
//printDeck prints the abbreviated names of each combat card in a deck 
void printDeck(CardNode *head)
{
	CardNode *current = head->next;
	int tempValue;
	char tempChar;
	while (current->info.Type != TAIL)
	{
		tempValue = current->info.Value;
		tempChar = typeToChar(current->info.Type);
		printf("%c%d ", tempChar, tempValue);
		// printf("for %d ", tempValue);
		current = current->next;
	}
	printf("\n");
}
//getDeckSize returns the number of combat cards in a deck from the head of a list
int getDeckSize(CardNode *head)
{
	CardNode *current = head->next;
	int counter = 0;

	while (current->info.Type != TAIL)
	{
		current = current->next;
		counter++;
	}
	return counter;
}
//printDeckSize prints the number of cards in the deck
void printDeckSize(CardNode *head)
{
	int deckSize = getDeckSize(head);
	printf("now has %d cards remaining in their deck!\n", deckSize);
}
//discard returns the head of a list after removing the first combat card from it
CardNode *discard(CardNode *head)
{

	CardNode *next;
	next = head->next;
	if (next->info.Type != TAIL)
	{
		head->next = next->next;
		free(next);
	}
	return head;
}
//cardCompare returns an int based on parameter card's type
int cardCompare(Card pCard)
{

	if (pCard.Type == ATTACK)
	{
		return 100;
	}
	if (pCard.Type == DEFEND)
	{
		return 10;
	}
	if (pCard.Type == RUN)
	{
		return 1;
	}
}
//cardBattle returns the head of a list and alters the list based on the first combat card and the opponents combat card
CardNode *cardBattle(CardNode *mainHead, Card otherDeck)
{

	CardNode *mainDeck = mainHead->next;
	int resolution = 0;
	resolution += cardCompare(mainDeck->info);
	resolution *= 2;
	resolution += cardCompare(otherDeck);

	int mainValue;
	mainValue = mainDeck->info.Value;
	int otherValue;
	otherValue = otherDeck.Value;
	//discard for turn
	mainDeck = discard(mainDeck);

	//AD
	if (resolution == 210)
	{

		if (mainValue > otherValue)
		{
			printf("they draw a new card!\n");
			mainDeck = drawCards(mainDeck, 1);
		}
		else
		{
			printf("they discard their next card!\n");
			mainDeck = discard(mainDeck);
		}
	}
	//DA
	else if (resolution == 120)
	{

		if (mainValue >= otherValue)
		{
			printf("they draw a new card!\n");
			mainDeck = drawCards(mainDeck, 1);
		}
	}
	//AA
	else if (resolution == 300)
	{

		if (mainValue > otherValue)
		{
			printf("they draw a new card!\n");
			mainDeck = drawCards(mainDeck, 1);
		}
		else if (mainValue < otherValue)
		{
			printf("they discard their next card!\n");
			mainDeck = discard(mainDeck);
		}
	}
	//RA,RD,RR
	else if (resolution == 102 || resolution == 12 || resolution == 3)
	{

		printf("they discard their next card!\n");
		mainDeck = discard(mainDeck);
	}
	//DR
	else if (resolution == 21)
	{

		printf("they draw a new card!\n");
		mainDeck = drawCards(mainDeck, 1);
	}
	else
	{

		printf("nothing happens!\n");
	}
	return mainDeck;
}
//openingCrawl prints information at the start of the game
void openingCrawl(CardNode *p1Head, CardNode *p2Head, int deckSize)
{
	printf("Starting deck size: %d cards\n", deckSize);
	printf("Player 1 starting cards: ");
	printDeck(p1Head);
	printf("Player 2 starting cards: ");
	printDeck(p2Head);
}
//attackAnnouncer prints the type of attacks that a play uses based on the input 
void attackAnnouncer(Card pCard)
{
	if (pCard.Type == DEFEND)
	{
		printf("defends for %d and ", pCard.Value);
	}
	if (pCard.Type == ATTACK)
	{
		printf("attacks for %d and ", pCard.Value);
	}
	if (pCard.Type == RUN)
	{
		printf("runs for %d and ", pCard.Value);
	}
}
//endOfGame prints the victor of the game based on the contents of their decks
void endOfGame(CardNode *p1Next, CardNode *p2Next, CardNode *p1Head, CardNode *p2Head)
{
	int victory = 0;

	if (p1Next->info.Type != TAIL)
	{
		printf("Player 1 deck:");
		printDeck(p1Head);
		victory++;
	}
	else
	{
		printf("Player 1 has run out of cards!\n");
	}

	if (p2Next->info.Type != TAIL)
	{
		printf("Player 2 deck:");
		printDeck(p2Head);
		victory--;
	}
	else
	{
		printf("Player 2 has run out of cards!\n");
	}

	if (victory > 0)
	{
		printf("Player 1 is victorious!\n");
	}
	else if (victory < 0)
	{
		printf("Player 2 is victorious!\n");
	}
	else
	{
		printf("No player won, it is a draw.\n");
	}
}