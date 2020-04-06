#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "routeRecords.h"

/*
 *	
 *	Project 2
 *	Matthew Henderson
 *	This program will sum a route's passengers in a file 
 *  and print it to another file
 *	it takes three strings as arguments 
 *  arg 1: The name of the input file .csv
 *  arg 2: OutputFileName.csv
 */

int main(int argc, char *argv[])
{
    char inputName[20];
    strcpy(inputName,argv[1]);
    FILE *inputFile;
    inputFile = fopen(inputName,"r");
    checkFileOpening(inputFile);

    RouteRecord *flights;
    flights = createRecords(inputFile);
    // int fileLength = createRecordsTest(inputFile);
    // flights = (RouteRecord *)malloc(sizeof(RouteRecord) * fileLength);
    
    int flightsLength;
    flightsLength = fillRecords(flights,inputFile);
    int i;
     for (i = 0; i < flightsLength; i++)
    {
    printf("%d|",i);
    printf("%s|",(*flights).origin);
    printf("%s|",(*flights).destination);
    printf("%s\n",(*flights).airline);
    flights++;
    }
    char key1[4];
    char key2[4];
    SearchType searchKind = 0;
    while (searchKind != 5) {
        searchKind = getMenuOption(key1,key2);
        for (i = 0; i < strlen(key1); i++)
        {
            key1[i] = toupper(key1[i]);
        }
        for (i = 0; i < strlen(key2); i++)
        {
            key2[i] = toupper(key2[i]);
        }

        searchRecords(flights,flightsLength,key1,key2,searchKind);
    }


    return 0;
}