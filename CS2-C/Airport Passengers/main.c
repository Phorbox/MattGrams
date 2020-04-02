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
 *  arg 1: InputFileName.csv
 *  arg 2: OutputFileName.csv
 *  arg 3: RouteId 2 letter string
 */

    int
    main(int argc, char *argv[])
{

    int length;
    Route *flights;

    char *inputName = argv[1];
    char *outputName = argv[2];
    char *routeID = argv[3];
    int i;
    for (i = 0; i < strlen(routeID); i++)
    {
        routeID[i] = toupper(routeID[i]);
    }
        printf("\n");
    if (inputName == NULL)
    {
        printf("You did not enter an input file name.\n");
        printf("What should be searched for the total number of passengers??\n");
        scanf("%s", routeID);
    }
    if (outputName == NULL)
    {
        printf("You did not enter an output file name.\n");
        printf("Where should the total numebr of passengers be saved?\n");
        scanf("%s", routeID);
    }
    if (routeID == NULL)
    {
        printf("You did not enter a Route ID.\n");
        printf("What is the 2 letter id of the specific route?\n");
        scanf("%s", routeID);
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