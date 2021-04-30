#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cardBattle.h"
#include <time.h>

/*
 *	Cardbattler
 *	project 1
 *	Matthew Henderson
 *	This program simulates a delve into a dungeon full of monsters
 */

int main(int argc, char *argv[])
{
    int deckSize = 12;
    srand(time(0));
    if(argc != 1){
       deckSize = atoi(argv[1]);
    }
    
    CardNode *p1Head;
    p1Head = constructDeck(deckSize);
    CardNode *p1Next;
    p1Next = p1Head->next;

    CardNode *p2Head;
    p2Head = constructDeck(deckSize);
    CardNode *p2Next;
    p2Next = p2Head->next;

    Card p1Card;
    Card p2Card;

    openingCrawl(p1Head, p2Head, deckSize);

    int round = 1;

    while (p1Next->info.Type != TAIL && p2Next->info.Type != TAIL)
    {
        printf("\nRound: %d\n", round);
        p1Card = p1Next->info;
        p2Card = p2Next->info;

        printf("Player 1 ");
        attackAnnouncer(p1Card);
        p1Head = cardBattle(p1Head, p2Card);
        printf("Player 1 ");
        printDeckSize(p1Head);

        printf("Player 2 ");
        attackAnnouncer(p2Card);
        p2Head = cardBattle(p2Head, p1Card);
        printf("Player 2 ");
        printDeckSize(p2Head);

        p1Next = p1Head->next;
        p2Next = p2Head->next;
        round++;
    }
    printf("\n");
    endOfGame(p1Next, p2Next, p1Head, p2Head);
}