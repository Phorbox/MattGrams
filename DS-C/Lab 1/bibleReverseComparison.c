#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "commonFunctionBible.h"
#include "iterativeBible.h"
#include "recursiveBible.h"


int main()
{
    char fileName[] = "bible.txt";

    clock_t start_t;
    clock_t end_t;

    printf("Starting of the Iterative Program, start_t = %ld\n", start_t);
    start_t = clock();
    reversalIterative(fileName);
    end_t = clock();
    printf("End of the program, end_t = %ld\n", end_t);
    writeTime(start_t, end_t);

    printf("Starting of the Recursive Program, start_t = %ld\n", start_t);
    start_t = clock();
    reversalRecursive(fileName);
    end_t = clock();
    printf("End of the program, end_t = %ld\n", end_t);
    writeTime(start_t, end_t);

    return 0;
}
