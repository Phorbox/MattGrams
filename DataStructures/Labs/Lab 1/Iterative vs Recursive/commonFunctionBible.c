

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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

void createOutputFilePointer(char *outputFileName, FILE *outputFile)
{
    //write to a new file containing the totalPassengers totalPassengers of employees
    outputFile = fopen(outputFileName, "w");
    int check;
    check = checkFileOpening(outputFile);
    if (check == -1)
    {
        return;
    }
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

void writeTime(clock_t start_t, clock_t end_t)
{
    // FILE *outputFile;
    // // outputFile = fopen("ReversedComparison.csv", "w");
    // int check;
    // check = checkFileOpening(outputFile);
    // if (check == -1)
    // {
    //     printf("error\n");
    //     return;
    // }

    double total_t;

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t);
    // fprintf(outputFile, "%f,", total_t);
    //fclose(outputFile);
}
