
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "commonFunctionBible.h"

int stringReverseRecursive(char *string, int indexBegin)
{
    char temporaryCharacter;
    int indexEnd;

    if (string[indexBegin] != '\0')
    {
        temporaryCharacter = string[indexBegin];
        indexEnd = stringReverseRecursive(string, indexBegin + 1) + 1;
        string[indexEnd] = temporaryCharacter;
        return indexEnd;
    }
    else
    {
        return -1;
    }
}

void lineReverseRecursive(FILE *inputFile, FILE *outputFile)
{
    char buffer[200];
    if (!feof(inputFile))
    {
        fgets(buffer, 200, inputFile);
        lineReverseRecursive(inputFile, outputFile);
        stringReverseRecursive(buffer, 0);
        fprintf(outputFile, "%s\n", buffer);
        return;
    }
    else
    {
        return;
    }
}

void reversalRecursive(char *inputFileName)
{

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
    outputFile = fopen("RecursiveBibleReversed.txt", "w");
    check = checkFileOpening(outputFile);
    if (check == -1)
    {
        printf("error\n");

        return;
    }

    lineReverseRecursive(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
}
