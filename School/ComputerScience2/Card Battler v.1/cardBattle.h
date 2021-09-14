#ifndef CARDBATTLE_H
#define CARDBATTLE_H

typedef enum CardType
{
	ATTACK,
	DEFEND,
	RUN,
	HEAD,
	TAIL
} CardType;

typedef struct Card_struct
{
	CardType Type;
	int Value;
} Card;

typedef struct CardNode_struct
{
	Card info;
	struct CardNode_struct *next;
} CardNode;

int generateRandomNumber(int min, int max);
CardType generateType();
CardType generateValue(CardType Input);
CardNode *constructCard();
CardNode *insertMiddle(CardNode *compare, int value);
CardNode *drawCards(CardNode *head, int addSize);
CardNode *constructHead();
CardNode *constructTail();
CardNode *seedList();
CardNode *constructDeck(int deckSize);
char typeToChar(CardType type);
void printDeck(CardNode *head);
int getDeckSize(CardNode *head);
void printDeckSize(CardNode *head);
CardNode *discard(CardNode *head);
int cardCompare(Card pCard);
CardNode *cardBattle(CardNode *mainHead, Card otherDeck);
void openingCrawl(CardNode *p1Head, CardNode *p2Head, int deckSize);
void attackAnnouncer(Card pCard);
void endOfGame(CardNode *p1Next, CardNode *p2Next, CardNode *p1Head, CardNode *p2Head);


#endif