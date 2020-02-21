#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 1. Declare your variables here */
    
    /* 2. change the seed for random */
    
    /* 3. Initialize the player struct object, to have 50 hitpoints and 0 experience points by default */
  
    /* 4. Dynamically allocate an array of Room structs with the number the user
       entered. Assume that the user has entered a positive number */
    
    /* 5. Call the fillRooms function() to create the rooms */

    /* 6. Print out a message to say how many rooms there are and that the challenge has started. */

    /* 7. Call printPlayer() to print out the beginning stats */

    /* 8. Taverse the array of rooms, for each room:
	
            8.1 Call enterRoom() 
			
	    8.2 Print out a message about how many hitpoints were lost or gained while in this room. Print out this value in a positive number (You lost 5 hitpoints while in this room).

            8.3 Determine if entering the room resulted in a gain in experience points, and print out an appropriate message stating as such. If not experience points were gained, do not print out a message.
		
            8.4	Update the player's hitpoints with the loss or gain. Never allow for the player's hitpoints to be negative. If it goes below zero, simply set the player's hitpoints to 0. If the player's hitpoints is zero, break the loop as the game is over.
			
            8.5	Update the player's experience points 
			
	    8.6 Call printPlayer() to print out the updated player's stats.

	9. Outside the loop, print out a message of congratulations if the player has any hitpoints left. If a player has zero hitpoints, print out a message of regret.
	10. deallocate the array of rooms.
			
    */
    return 0;
}