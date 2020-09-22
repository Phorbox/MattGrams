
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "commonFunctionBible.h"


void reversalRecursive(char *fileName)   
{

    FILE *inputFile;
    inputFile = createInputFilePointer(fileName);
    
    FILE *outputFile;
    outputFile = createOutputFilePointer("RecursiveBibleReversed.txt");

    lineReverseRecursive(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

}

void lineReverseRecursive(FILE *inputFile,FILE *outputFile)
{
    char buffer[1000];
    if (!feof(inputFile))
    {
        fgets(buffer, 1000, inputFile);
        lineReverseRecursive(inputFile, outputFile);
        stringReverseRecursive(buffer, 0);
        fprintf(outputFile,"%s\n",buffer);
        return;
    } else {
        return;
    }
}

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

