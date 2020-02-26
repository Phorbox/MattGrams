#include <stdio.h>

//Enumerates the types of rooms
typedef enum TYPE { EMPTY, PRIZE, MONSTER} TYPE; 

//Struct to represent monsters and players.
typedef struct Entity_struct
{
	int hitPoints;
	int experiencePoints;
} Entity;

//struct to represent prize/treasure rooms
typedef struct Prize_struct
{
	int points;

} Prize;

//stuct to represent rooms, named encounter for readability
typedef struct Room_struct
{
	TYPE type;
	Entity monster;
	Prize prize;
} Encounter;

//generates a random number between min and max inclusive
int getRandomNumber(int min, int max)
{
	int n;	

	n = (rand() % (max-min)) + min;

	return n;
}

//fills the current room
void fillRoom(Encounter* currentRoom )
{
		
	int reward = 0;
	
	int typeR = getRandomNumber(0,9);

	//populate monster
	if(typeR == 0)
	{
		currentRoom->type = 0;
	}else if(typeR < 5)
	//populate prize
	
	{
		currentRoom->type = 1;
		reward = getRandomNumber(5,10);
		currentRoom->prize.points = reward;
 	}else 
	 
	{
		currentRoom->type = 2;
		int HP = getRandomNumber(10,30);
		
		if((HP % 3) == 0)
		{
			reward = 1;
		}
		currentRoom->monster.hitPoints = HP;
		currentRoom->monster.experiencePoints = reward;	
	}
	 
}

//applies fill room to the entire dungeon
void fillDungeon(Encounter* room , int length)
{
	int i;
	for(i = 0 ; i < length ; i++ )
	{
		
		fillRoom(&room[i]);
		
	}
}

//announces the status of the player
void printPlayer(Entity* player)
{
	printf("\nPlayer (HP: %d, XP: %d)\n", player->hitPoints , player->experiencePoints);
}

//operates the player by the rooms info
void enterRoom(Entity* player , Encounter* currentRoom )
{
	//Enter Monster room
	if(currentRoom->type == 2)
	{
		printf("a monster! (HP: %d , XP: %d)\n", currentRoom->monster.hitPoints , currentRoom->monster.experiencePoints);
		player->hitPoints -= currentRoom->monster.hitPoints;
		player->experiencePoints += currentRoom->monster.experiencePoints;
		printf("You lost %d hitpoints from this room\n" , currentRoom->monster.hitPoints);
	} else if(currentRoom->type == 1)

	//Enter Prize room
	
	{
		printf("a glorious prize!\n");
		(*player).hitPoints += currentRoom->prize.points;
	} else if(currentRoom->type == 0)

	//Enter Empty room
	
	{
		printf("cold nothingness, what will the next room hold?\n");

	}
	printPlayer(player);
}

//apples enterRoom and the player to the entire dungeon
void enterDungeon(Entity* player , Encounter* room , int length)
{
	int i = 0;
	
	while(i < length)
	{
		//Defeat Check
		if (player->hitPoints <= 0)
		{
			printf("You did not survive the monster battle! GAME OVER.\n");
			printf("You had earned %d experience, and entered %d doors\n", player->experiencePoints , i);
			i += length;
		} 
		//open door
		else 
		{
			
			printf("you open the door to room #%d, and find...\n\n", i + 1);
			enterRoom(player , &room[i]);
			
		}

		i++;
	}

	// Victory read the closing statement
	if(player->hitPoints > 0)
	{
		printf("You did survive the monster battle! VICTORIOUS.\n");
		printf("you had earned %d experience, and entered %d doors\n", player->experiencePoints , i);

	}
}

