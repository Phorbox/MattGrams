#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "routeRecords.h"

/*
 *	
 *	Assignment 7
 *	Matthew Henderson
 *	This program will sum a route's passengers in a file 
 *  and print it to another file
 *	it takes three strings as arguments 
 *  arg 1: The name of the input file .csv
 *  arg 2: OutputFileName.csv
 *  arg 3: RouteId 2 letter string
 */

    int
    main(int argc, char *argv[])
{

    int length;
    Route *flights;

    char inputName[20]; 
    strcpy(inputName,argv[1]);
    char outputName[20];
    strcpy(outputName,argv[2]);
    char *routeID = argv[3];
    
    

        printf("\n");
    if (inputName == NULL)
    {
        printf("You did not enter an input file name.\n");
        printf("What file should be searched for the total number of passengers?\n");
        scanf("%s", routeID);
    }
    if (outputName == NULL)
    {
        printf("You did not enter an output file name.\n");
        printf("Which file should save the total number of passengers?\n");
        scanf("%s", routeID);
    }
    if (routeID == NULL || strlen(routeID) != 2)
    {
        printf("You did not enter a valid Route ID.\n");
        printf("What is the 2 letter id of the route?\n");
        scanf("%s", routeID);
    }

    //makes sure that user input had correct file type
    char fileType[] = ".csv";
    if (strstr(inputName,fileType) == NULL)
    {
        strcat(inputName,fileType);
    }
    if (strstr(outputName,fileType) == NULL)
    {
        strcat(outputName,fileType);
    }
    //makes sure that route id has the correct casing 
    int i;
    for (i = 0; i < strlen(routeID); i++)
    {
        routeID[i] = toupper(routeID[i]);
    }

    printf("This program will will search \"%s\" for route %s's total passengers, then save it to \"%s\"\n", inputName, routeID, outputName);
    printf("\nGetting the length of %s.\n", inputName);
    length = getFileLength(inputName);

    printf("Reading the contents of %s.\n", inputName);
    flights = getFileContent(inputName, length);

    printf("Writing the total passengers of %s to %s\n", routeID, outputName);
    getFlightPassengers(flights, length, outputName, routeID);

    printf("Done!\n\n");

    return 0;
}