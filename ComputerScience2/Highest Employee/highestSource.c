#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "employee.h"

int main(int argc, char *argv[])
{
    //assuming file names are "inputData.txt" and "outputData.txt"
    int length;
    char outFile[] = "outputData.txt";
    char inFile[] = "inputData.txt";
    Employee *company;
    int test[2];

    printf("\nThis program will create a file of the highest paid employees");
    printf("\nGetting the length of the file.");
    length = getFileLength(inFile);
    printf("\nReading file contents.");
    company = getFileContent(inFile, length);
    printf("\nCreating a new file.");
    getEmployeeWithHigestSalary(company, length, outFile);
    printf("\nDone\n!");

    return 0;
}
