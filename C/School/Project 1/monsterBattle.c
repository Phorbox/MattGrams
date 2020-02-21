
typedef enum TYPE { EMPTY, PRIZE, MONSTER} TYPE; 

typedef struct Character
{
	int hitPoints;
	int experiencePoints;
}

typedef struct Prize
{
	int points;
} Prize;

typedef struct Room
{
	TYPE type;
	Character monster;
	Prize prize;
} Room;

int getRandomNumber(int min, int max)
{
	int n;	
		//32 - 8 = 24
	n = (rand() % (max-min)) + min

	return n;
}


void fillRoom(Room *rooms , int roomID){
	// make dynamic ex: if the types of room changes.
	*rooms[roomID]->TYPE = getRandomNumber(0,2);




}


void fillDungeon(){

}
