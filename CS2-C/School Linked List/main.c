#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"


/*
 *	
 *	Assignment 9
 *	Matthew Henderson
 *	This program will sort a csv of students 
 *  and allow the user to search it for a single id
 *	it takes 1 strin as arguments
 *  arg 1: The name of the input file .csv
 */
int main(int argc, char *argv[])
{
    char inputName[100];
    strcpy(inputName, argv[1]);

    FILE *inputFile;

    printf("\nReading %s... \n", inputName);
    inputFile = fopen(inputName, "r");
    if (checkFileOpening(inputFile) == -1)
    {
        printf("error, %s did not open properly ... \n", inputName);
        return -1;
    }
    int fileLength = getFileLength(inputFile);

    printf("Creating the student list... \n");
    LLNodeStudent *schoolHead;
    schoolHead = seedStudentLL();
    fillSchool(schoolHead, inputFile);

    printf("Students list sorted by name alphabetically." );
    printList(schoolHead);

    printf("Sorting the student list by id number... \n");
    schoolHead = bubbleSort(schoolHead);

    printf("Students list sorted by name alphabetically." );
    printList(schoolHead);

    freeList(schoolHead);
    return 0;
}