
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fileIn.h"



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


void createInputFilePointer(char *inputFileName, FILE *inputFile)
{
    //write to a new file containing the totalPassengers totalPassengers of employees
    inputFile = fopen(inputFileName, "r");
    int check;
    check = checkFileOpening(inputFile);
    if (check == -1)
    {
        printf("error\n");
        return;
    }
}

char *fileNameAssumption(char *fileName)
{
    char *replacementName;
    char check;
    printf("The default file name is %s. would you like to change it?\n", fileName);
    scanf("%c",&check);
    printf("Y/N\n");
    if ((check == 'Y') || (check == 'y'))
    {
        printf("What is the file name?");
        scanf("%s",replacementName);
    } else
    {
        replacementName = fileName;
    }
    

    return replacementName;
}

int getFileLength(char *fileName)
{
    //creates file pointer
    int fileLength;
    FILE *inputFile;
    inputFile = fopen(fileName, "r");
    int check = checkFileOpening(inputFile);
    if(check == -1){
        return -1;
    }

    //counts the number of lines
    char buffer[50];
    int filelength = 0;
    while (!feof(inputFile))
    {
        fgets(buffer, 50, inputFile);
        fileLength++;
    }
    fclose(inputFile);
    return fileLength;
}