#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Route is the combination of a flight's origin, destination, id, and number of passengers
typedef struct Route_struct
{
    char origin[3];
    char destination[3];
    char id[2];
    int passengers;
} Route;

// checkFileOpening returns -1 if inFile opened improperly, and 0 otherwise
int checkFileOpening(FILE *inFile)
{
    int output = 0;

    if (inFile == NULL)
    {
        printf("Error\n");
        output = -1;
    }
    return output;
}

// getFileLength returns an int of the length of fileName 
int getFileLength(char *fileName)
{
    //creates file pointer
    int output;
    FILE *inFile;
    inFile = fopen(fileName, "r");
    output = checkFileOpening(inFile);

    //counts the number of lines
    char buffer[1000];
    while (!feof(inFile) && output != -1)
    {
        fgets(buffer, 1000, inFile);
        output++;
    }
    fclose(inFile);
    return output;
}

// Route returns an array of Routes from fileName and its length
Route *getFileContent(char *fileName, int length)
{
    FILE *inFile = fopen(fileName, "r");

    int check = checkFileOpening(inFile);

    int i = 0;
    char buffer[1000];
    Route *flights = (Route *)malloc(sizeof(Route) * length);

    //Temporary Variables
    char origin[3];
    char destination[3];
    char id[2];
    int passengers;

    while (!feof(inFile) && i < length && check != -1)
    {
        //stores the next line of file to buffer
        fgets(buffer, 1000, inFile);

        //This parses buffer to the temporary variables
        sscanf(buffer, "%3[^,],%3[^,],%2[^,],%d", origin, destination, id, &passengers);
            
        //fills the employee array with content
        strcpy(flights[i].origin, origin);
        strcpy(flights[i].destination, destination);
        strcpy(flights[i].id, id);
        flights[i].passengers = passengers;

        i++;
    }

   
    fclose(inFile);
    return flights;
}

// getFlightPassengers creates a file with the sum of passengers in it from flights, its length, the outputFileName, and the routeName    
void getFlightPassengers(Route *flights, int length, char *outputFileName, char *routeName)
{
    int i;
    int totalPassengers = 0;

    for (i = 0; i < length; i++)
    {
        if (strcmp(flights[i].id, routeName) == 0)
        {
            totalPassengers += flights[i].passengers;
        }
    }

    //write to a new file containing the totalPassengers totalPassengers of employees
    FILE *outFile;
    outFile = fopen(outputFileName, "w");
    int check = checkFileOpening(outFile);
    fprintf(outFile, "%d", totalPassengers);
    fclose(outFile);
}