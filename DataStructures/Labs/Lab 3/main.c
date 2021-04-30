#include <stdlib.h>
#include <stdio.h>
#include "fileIn.h"
#include "postFix.h"
#include <string.h>

// Author: Matthew Henderson    
// Assignment Number: lab 03
// File Name: LAB03_Henderson.zip
// Course/Section: CS 2123 Section 0D1
// Date: 10/27/20
// Instructor: Bernard Ku



int main(int argc, char *argv[])
{
    postfixStack stark;
    stark.stackIndex = 0;

    char fileName[50];
    printf("What is the file name? \n");
    scanf("%s", fileName);
    printf("\nThe filename is %s\n", fileName);

    FILE *inputFile;
    inputFile = fopen(fileName, "r");

    if (inputFile == NULL)
    {
        printf("error opening file\n");
        return;
    }

    int fileLength;
    fileLength = getFileLength(fileName);
    printf("The file is %d lines long\n\n", fileLength);

    char *buffer = NULL;
    size_t bufferSize;
    int i = 0;
    while (i < fileLength)
    {
        // memset(buffer,'\0',50);
        getline(&buffer, &bufferSize, inputFile);
        stark.stackIndex = 0;
        readTape(buffer, &stark);
        i++;
    }
    fclose(inputFile);
    free(buffer);
    return 0;
}
