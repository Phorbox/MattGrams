#ifndef ROUTERECORDS_H
#define ROUTERECORDS_H

typedef struct Route_struct
{
    char origin[3];
    char destination[3];
    char id[2];
    int passengers;
} Route;

int getFileLength(char *fileName);
int checkFileOpening(FILE *inFile);
Route *getFileContent(char *fileName, int length);
void getFlightPassengers(Route *flights, int length, char *outFileName, char *name);

#endif