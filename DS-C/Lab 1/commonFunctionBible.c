

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

FILE *createOutputFilePointer(char *outputFileName)
{
    //write to a new file containing the totalPassengers totalPassengers of employees
    FILE *outFile;
    outFile = fopen(outputFileName, "w");
    int check;
    check = checkFileOpening(outFile);
    if (check == -1)
    {
        return NULL;
    }
    return outFile;
}

FILE *createInputFilePointer(char *inputFileName)
{
    //write to a new file containing the totalPassengers totalPassengers of employees
    FILE *inFile;
    inFile = fopen(inputFileName, "r");
    int check;
    check = checkFileOpening(inFile);
    if (check == -1)
    {
        return NULL;
    }
    return inFile;
}

void writeTime(clock_t start_t, clock_t end_t)
{
    FILE *outFile;
    createOutputFilePointer("timeComparison.csv");
    
    clock_t total_t;

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );
    fprintf(outFile, "%f\n", total_t);
    fclose(outFile);
}
