#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "commonFunctionBible.h"

// getFileLength returns an int of the length of fileName
int getFileLengthIterative(char *fileName)
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
    char buffer[500];
    int filelength = 0;
    while (!feof(inputFile))
    {
        fgets(buffer, 500, inputFile);
        fileLength++;
    }
    fclose(inputFile);
    return fileLength;
}

// getFileLength returns nothing but reverses the contents of a char array
void stringReverseIterative(char *string)
{
    char temporaryCharacter;

    int stringLength = strlen(string);
    int begin;
    int end = stringLength - 1;
    string[stringLength] = '\n';

    for (begin = 0; begin <= end; begin++)
    {
        temporaryCharacter = *(string + begin);
        *(string + begin) = *(string + end);
        *(string + end) = temporaryCharacter;
        end--;
    }
}

char *populateStringArrayIterative(FILE *inputFile, int fileLength)
{
    //FileContents is an array of char arrays accessed with pointer notation
    char *fileContents;
    int rowLength = 500;
    fileContents = (char *)malloc(rowLength * fileLength * sizeof(char));

    char buffer[500];
    int currentFileLine = 0;
    int whereItGoes = fileLength;

    while (!feof(inputFile) && currentFileLine <= fileLength)
    {
        fgets(buffer, 500, inputFile);
        // printf("%d | %s\n", currentFileLine, buffer);
        stringReverseIterative(buffer);
        // printf("%d | %s\n", currentFileLine, buffer);
        strcpy((fileContents + (whereItGoes * rowLength)), buffer);
        // printf("%d | %s\n", currentFileLine, (fileContents + (whereItGoes * rowLength)));
        whereItGoes--;
        currentFileLine++;
    }

    return fileContents;
}

void populateOutputFile(FILE *outputFile, char *reversedContents, int fileLength)
{
    char temporaryString[500];
    int rowLength = 500;
    int i;
    for (i = 0; i < fileLength; i++)
    {
        strcpy(temporaryString, reversedContents + (rowLength * i));
        fprintf(outputFile, "%s\n", temporaryString);
    }
}

void reversalIterative(char *inputFileName)
{
    int fileLength = 0;
    fileLength = getFileLengthIterative(inputFileName);

    FILE *inputFile;
    inputFile = fopen(inputFileName, "r");
    int check;
    check = checkFileOpening(inputFile);
    if (check == -1)
    {
        printf("error\n");
        return;
    }

    FILE *outputFile;
    outputFile = fopen("IterativeBibleReversed.txt", "w");
    check = checkFileOpening(outputFile);
    if (check == -1)
    {
        printf("error\n");
        return;
    }

    char *reversedContents;
    reversedContents = populateStringArrayIterative(inputFile, fileLength);

    populateOutputFile(outputFile, reversedContents, fileLength);

    fclose(inputFile);
    fclose(outputFile);
}
