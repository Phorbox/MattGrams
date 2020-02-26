#include <stdio.h>
#include <stdlib.h>
#include "monsterBattle.h"


/*
 *	monsterBattleSource.C
 *	project 1
 *	Matthew Henderson
 *	This program simulates a delve into a dungeon full of monsters
 */

int main()
{
    //main Variables
    Entity player;
    Encounter *dungeon;
    int length = 0;

    //Seeds the random
    //srand(1);
    
    //Creates player pointer
    player.hitPoints = 50;
    player.experiencePoints = 0;
    printf("Welcome to the MONSTER BATTLE rooms v.1\n");
    while(length < 1)
    {
        printf("\nHow many rooms do you wish to challenge?\n");
        scanf("%d", &length);
        if(length < 1)
        {
            printf("\n%d is an invalid number of rooms, please choose a number greater than zero.\n",length);
        }
    }
    printf("You have chosen to endure %d rooms. Let the challenge begin.\n", length);
    dungeon = (Encounter*)malloc(length*sizeof(Encounter));


    fillDungeon(dungeon , length);
    printPlayer(&player);
    enterDungeon(&player , dungeon , length);

    free(dungeon);
    
    return 0;
}