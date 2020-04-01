#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H

typedef enum TYPE
{
	EMPTY,
	PRIZE,
	MONSTER
} TYPE;

typedef struct Entity_struct
{
	int hitPoints;
	int experiencePoints;
} Entity;

typedef struct Prize_struct
{
	int points;

} Prize;

typedef struct Room_struct
{
	TYPE type;
	Entity monster;
	Prize prize;
} Encounter;

int getRandomNumber(int min, int max);
void fillRoom(Encounter *currentRoom);
void fillDungeon(Encounter *room, int length);
void printPlayer(Entity *player);
void enterRoom(Entity *player, Encounter *currentRoom);
void enterDungeon(Entity *player, Encounter *room, int length);

#endif