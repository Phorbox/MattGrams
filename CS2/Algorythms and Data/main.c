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

    printf("Creating the student array... \n");
    Student *school;
    school = (Student *)malloc(fileLength * sizeof(Student));
    fillSchool(school, inputFile);

    printf("Sorting the student array... \n");
    mergeSort(school, 0, fileLength - 1);

    int i = 0;
    if (fileLength > 1)
    {

        printf("\nThe names for students in sorted order of their IDs are ");

        for (i = 0; i < fileLength - 1; i++)
        {
            printf("%s, ", school[i].name);
        }
        printf("and %s \n", school[fileLength - 1].name);
    }
    else
    {
        printf("\nThe name of the student in sorted order of their ID is %s\n", school[fileLength - 1].name);
    }

    int inputID;
    printf("Enter student id: ");
    scanf("%d", &inputID);

    int studentFound;
    studentFound = binarySearch(school, fileLength, inputID);

    if (studentFound == -1)
    {
        printf("\nNo student record found for id: %d\n", inputID);
    }
    else
    {
        printf("\nInformation of the found student is\n");
        printf("ID      : %d\n", school[studentFound].id);
        printf("Name    : %s\n", school[studentFound].name);
        printf("Age     : %d\n", school[studentFound].age);
        printf("GPA     : %lf\n", school[studentFound].gpa);
    }
    free(school);
    return 0;
}