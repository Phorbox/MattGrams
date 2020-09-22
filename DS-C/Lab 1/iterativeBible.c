#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "commonFunctionBible.h"



void reversalIterative(char *fileName)
{
    FILE *inputFile;
    inputFile = createInputFilePointer(fileName);

    FILE *outputFile;
    outputFile = createOutputFilePointer("IterativeBibleReversed.txt");

    int fileLength;
    fileLength = getFileLengthIterative(fileName);

    char *reversedContents;
    reversedContents = populateStringArrayIterative(outputFile, fileLength);
    populateOutputFile(outputFile, reversedContents, fileLength);

    fclose(inputFile);
    fclose(outputFile);
}

char *populateStringArrayIterative(FILE *inputFile, int fileLength)
{
    //FileContents is an array of char arrays accessed with pointer notation
    char *fileContents;
    int rowLength = 1000;
    fileContents = (char *)malloc(rowLength * fileLength * sizeof(char));

    char buffer[1000];
    int currentFileLine = 0;
    int whereItGoes = fileLength;

    while (!feof(inputFile) && currentFileLine < fileLength)
    {
        fgets(buffer, 1000, inputFile);
        stringReverseIterative(buffer);
        strcpy((fileContents + whereItGoes * rowLength), buffer);
        whereItGoes--;
        currentFileLine++;
    }
    return fileContents;
}

// getFileLength returns nothing but reverses the contents of a char array
void stringReverseIterative(char *s)
{
    char temporaryCharacter;

    int stringLength = strlen(s);
    int begin;
    int end = stringLength - 1;

    for (begin = 0; begin <= end; begin++)
    {
        temporaryCharacter = *(s + begin);
        *(s + begin) = *(s + end);
        *(s + end) = temporaryCharacter;
        end--;
    }
}

// getFileLength returns an int of the length of fileName
int getFileLengthIterative(char *fileName)
{
    //creates file pointer
    int fileLength;
    FILE *inputFile;
    inputFile = fopen(fileName, "r");
    fileLength = checkFileOpening(inputFile);

    //counts the number of lines
    char buffer[1000];
    while (!feof(inputFile) && fileLength != -1)
    {
        fgets(buffer, 1000, inputFile);
        fileLength++;
    }
    fclose(inputFile);
    return fileLength;
}

void populateOutputFile(FILE *outputFile, char *reversedContents, int fileLength)
{
    char *temporaryString;
    int rowLength = 1000;
    for (int i = 0; i < fileLength; i++)
    {
        temporaryString = reversedContents + rowLength * i; 
        fprintf(outputFile, "%s\n", temporaryString);
    }
}
