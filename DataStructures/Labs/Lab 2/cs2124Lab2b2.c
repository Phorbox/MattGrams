#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h> //To use the string functions strcpy

// Partial Author: Matthew Henderson
// Assignment Number: Lab 02
// File Name: cs2124Lab2
// Course/Section: CS 2123 Section 0D1
// Date: 10/5/20
// Instructor: Bernard Ku

const char DATA_FILE_NAME[] = "TestData.txt";

typedef struct functionRuntimes
{
    char *name;           //name of the function being tested
    double **times;       //run times
    double *avg;          //average runtime
    int numTestCases;     //number of times to repeat each test size
    int numTestCaseSizes; //number of test sizes
    int *testCaseSizes;   //array containing the test sizes
} functionRuntimes;

//Functions used to test the runtimes
functionRuntimes timeAlgorithm(char *, int, int, int[], void (*f)(FILE *));
FILE *generateTestInput(int, int, int);
void computeAvg(functionRuntimes fRT);
void printRuntimeTable(functionRuntimes fRT);
void freeFunctionRuntimes(functionRuntimes fRT);

//Functions whose runtime will be tested (and helper functions)
void insertionSortInitial(FILE *input);
void insertionSort(int *points, int low, int high);
void quickSortOptInitial(FILE *input);
void quickSortOpt(int *points, int low, int high);
int partition(int *points, int low, int high);

void MergeSort(int *arr, int low, int high);
void Merge(int *arr, int low, int mid, int high);
void MergeSortOptInitial(FILE *input);
void mysteryRuntime1(FILE *input);
void mysteryRuntime2(FILE *input);
void mysteryRuntime3(FILE *input);

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 * (if you make alterations plan to revert them before submission)
 */
int main(int argc, char *argv[])
{
    functionRuntimes fRT;

    int sizes1[] = {100000, 250000, 500000, 750000, 1000000};
    // int sizes2[] = {1000, 2000, 4000, 8000};

    srand(time(0));

    // fRT = timeAlgorithm("Insertion Sort", 10, 5, sizes1, insertionSortInitial);
    // printRuntimeTable(fRT);
    // freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("quicksort (uses insertion sort when sorting <30 numbers)", 10, 5, sizes1, quickSortOptInitial);
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    fRT = timeAlgorithm("Merge Sort", 10, 5, sizes1, MergeSortOptInitial);
    printRuntimeTable(fRT);
    freeFunctionRuntimes(fRT);

    // fRT = timeAlgorithm("Mystery 1", 8, 4, sizes2, mysteryRuntime1);
    // printRuntimeTable(fRT);
    // freeFunctionRuntimes(fRT);

    // fRT = timeAlgorithm("Mystery 2", 8, 4, sizes2, mysteryRuntime2);
    // printRuntimeTable(fRT);
    // freeFunctionRuntimes(fRT);

    // fRT = timeAlgorithm("Mystery 3", 8, 4, sizes2, mysteryRuntime3);
    // printRuntimeTable(fRT);
    // freeFunctionRuntimes(fRT);

    return 0;
}

/*************************************** Functions to have their runtimes tested *********************************************/

void MergeSortOptInitial(FILE *input)

{
    int i;
    int size;
    int *array;

    fscanf(input, "%d", &size);
    array = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        fscanf(input, "%d", &array[i]);
    }

    MergeSort(array, 0,size - 1);
}

void Merge(char *arr, int low, int mid, int high) //Merging the Array Function
{
    int nL = mid - low + 1;
    int nR = high - mid;

    int *L = malloc(sizeof(int) * nL);
    int *R = malloc(sizeof(int) * nR);
    int i;
    for (i = 0; i < nL; i++)
    {
        L[i] = malloc(sizeof(arr[low + i]));
        L[i] = arr[low + i];
    }
    for (i = 0; i < nR; i++)
    {
        R[i] = malloc(sizeof(arr[mid + i + 1]));
        R[i] = arr[mid + i + 1];
    }
    int j = 0, k;
    i = 0;
    k = low;
    while (i < nL && j < nR)
    {
        if (strcmp(L[i], R[j]) < 0)
            strcpy(arr[k++], L[i++]);
        else
            strcpy(arr[k++], R[j++]);
    }
    while (i < nL)
        strcpy(arr[k++], L[i++]);
    while (j < nR)
        strcpy(arr[k++], R[j++]);
}

void MergeSort(char *arr, int low, int high) //Main MergeSort function
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

/* provided code - DO NOT CHANGE
 */
void mysteryRuntime1(FILE *input)
{
    int temp;
    int size;
    int i = 0;
    int *array;

    if (fscanf(input, "%d", &size) != 1)
    {
        exit(-1);
    }
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        exit(-1);
    }

    while (fscanf(input, "%d", &temp) == 1 && i < size)
    {
        array[i] = temp;
        i++;
    }

    while (size > 1)
    {
        size = size / 2;
        array[size / 2] = array[size];
    }

    free(array);
}

/* provided code - DO NOT CHANGE
 */
void mysteryRuntime2(FILE *input)
{
    int temp;
    int size;
    int i = 0, j = 0;
    int *array;

    if (fscanf(input, "%d", &size) != 1)
    {
        exit(-1);
    }
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        exit(-1);
    }

    while (fscanf(input, "%d", &temp) == 1 && i < size)
    {
        array[i] = temp;
        i++;
    }

    i = 0;
    while (j < size)
    {
        array[j] = array[i];

        i++;
        if (i >= size)
        {
            j++;
            i = 0;
        }
    }

    free(array);
}

/* provided code - DO NOT CHANGE
 */
void mysteryRuntime3(FILE *input)
{
    int temp;
    int size;
    int n;
    int i = 0;
    int *array;

    if (fscanf(input, "%d", &size) != 1)
    {
        exit(-1);
    }
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL)
    {
        exit(-1);
    }

    while (fscanf(input, "%d", &temp) == 1 && i < size)
    {
        array[i] = temp;
        i++;
    }

    for (i = 0; i < size; i++)
    {
        for (n = size - 1; n > 1; n /= 1.01)
        {
            array[n - 1] = array[n];
        }
    }

    free(array);
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void insertionSortInitial(FILE *input)
{
    int i;
    int size;
    int *array;

    fscanf(input, "%d", &size);
    array = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        fscanf(input, "%d", &array[i]);
    }

    insertionSort(array, 0, size - 1);

    //Error check to verify the array is sorted
    /*for( i=1; i<size; i++)
    {
        if(array[i-1]>array[i])
        {
            printf("Not sorted!");
            exit(-1);
        }
    }*/

    free(array);
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void insertionSort(int *points, int low, int high)
{
    int i, j;
    double temp;

    for (i = low + 1; i <= high; i++)
    {
        for (j = i; j > low && points[j] < points[j - 1]; j--)
        {
            temp = points[j];
            points[j] = points[j - 1];
            points[j - 1] = temp;
        }
    }
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void quickSortOptInitial(FILE *input)
{
    int i;
    int size;
    int *array;

    fscanf(input, "%d", &size);
    array = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        fscanf(input, "%d", &array[i]);
    }

    quickSortOpt(array, 0, size - 1);

    //Error check to verify the array is sorted
    /*for( i=1; i<size; i++)
    {
        if(array[i-1]>array[i]){
            printf("Not sorted!");
            exit(-1);
        }
    }*/

    free(array);
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
void quickSortOpt(int *points, int low, int high)
{
    if (high < low + 30)
    {
        insertionSort(points, low, high);
    }
    else
    {
        int pivot = partition(points, low, high);

        quickSortOpt(points, low, pivot - 1);
        quickSortOpt(points, pivot + 1, high);
    }
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
int partition(int *points, int low, int high)
{
    int pivot = rand() % (high - low + 1) + low;
    int pivotValue = points[pivot];
    int i = low + 1;
    int j = high;
    int temp;

    points[pivot] = points[low];
    points[low] = pivotValue;

    while (i < j)
    {
        while (i <= high && points[i] <= pivotValue)
        {
            i++;
        }
        while (j >= low && points[j] > pivotValue)
        {
            j--;
        }
        if (i < j) //swap out of order elements
        {
            temp = points[i];
            points[i] = points[j];
            points[j] = temp;
        }
    }
    if (i <= high && points[i] <= pivotValue)
    {
        i++;
    }

    points[low] = points[i - 1];
    points[i - 1] = pivotValue;

    return i - 1;
}

/*************************************** Functions for finding and printing runtime *********************************************/

/*
Give your asymptotic estimates for the runtimes of the following 3 functions:

mysteryRuntime1:  O(   N   )
mysteryRuntime2:  O(  N^2  )
mysteryRuntime3:  O( NlogN )
*/

/* TO BE COMPLETED BY YOU
 * Fill in the missing parts of the code (see TODOs below)
 */
functionRuntimes timeAlgorithm(char *name, int numTestCases, int numTestCaseSizes, int testCaseSizes[], void (*f)(FILE *))
{
    /* Call and calculate the runtime of the provided function f */
    clock_t start, end;
    int i, j;
    FILE *testData;

    //create functionRuntimes variable to return
    functionRuntimes fRT;

    //TODO: copy passed data into the fRT variable

    fRT.name = name;                         //name of the function being tested
    fRT.numTestCases = numTestCases;         //number of times to repeat each test size
    fRT.numTestCaseSizes = numTestCaseSizes; //number of test sizes
    fRT.testCaseSizes = NULL;
    fRT.testCaseSizes = (int *)malloc(numTestCaseSizes * sizeof(int));
    if (fRT.times == NULL)
    {
        exit(-1);
    }

    for (i = 0; i < numTestCaseSizes; i++)
    {
        fRT.testCaseSizes[i] = testCaseSizes[i];
    }

    //TODO: initialize and fill in the runtimes table
    fRT.times = NULL /* instead malloc an array of double*s of size numTestCaseSizes */;

    fRT.times = (double **)malloc(numTestCaseSizes * sizeof(double *));
    if (fRT.times == NULL)
    {
        exit(-1);
    }

    for (i = 0; i < numTestCaseSizes; i++)
    {
        fRT.times[i] = NULL /* instead malloc an array of doubles of size numTestCases */;
        fRT.times[i] = (double *)malloc(numTestCases * sizeof(double));
        if (fRT.times[i] == NULL)
        {
            exit(-1);
        }

        for (j = 0; j < numTestCases; j++)
        {
            //Generate test data for the function f
            testData = generateTestInput(0, testCaseSizes[i], testCaseSizes[i]);

            //Run f on the generated test data
            start = clock();
            f(testData);
            end = clock();
            fclose(testData);

            //Enter the elapsed number of seconds into the times array for fRT
            fRT.times[i][j] = (double)(end - start) / CLOCKS_PER_SEC;
        }
    }

    //TODO: Calculte the average runtimes (call computeAvg here)
    fRT.avg = (double *)malloc(numTestCases * sizeof(double *));
    if (fRT.avg == NULL)
    {
        exit(-1);
    }
    computeAvg(fRT);

    return fRT;
}

/*
 * Provided code - DO NOT CHANGE THIS METHOD
 */
FILE *generateTestInput(int min, int max, int size)
{
    int i;
    FILE *data = fopen(DATA_FILE_NAME, "w");

    if (data == NULL)
    {
        printf("Failed to create file %s\n", DATA_FILE_NAME);
        exit(-1);
    }

    //add size to start of file
    fprintf(data, "%d ", size);
    //Fill the file with random data
    for (i = 0; i < size; i++)
    {
        fprintf(data, "%d ", rand() % (max - min + 1) + min);
    }
    fclose(data);

    data = fopen(DATA_FILE_NAME, "r");
    if (data == NULL)
    {
        printf("Failed to create file %s\n", DATA_FILE_NAME);
        exit(-1);
    }
    return data;
}

/* TO BE COMPLETED BY YOU
 * Calculate and insert the average runtime for each set of test data into fRT
 */
void computeAvg(functionRuntimes fRT)
{

    int vertical, horizontal;
    double summedRunTime;
    int numberOfRuns;

    for (vertical = 0; vertical < fRT.numTestCaseSizes; vertical++)
    {
        numberOfRuns = fRT.numTestCases;

        for (horizontal = 0; horizontal < fRT.numTestCases; horizontal++)
        {
            summedRunTime += fRT.times[vertical][horizontal];
        }
        fRT.avg[vertical] = summedRunTime / numberOfRuns;
    }
}

/* TO BE COMPLETED BY YOU
 * Print the information in fRT as a 2d table.  Display 3 digits after the decimal point.  You can assume all of the runtimes are <= 99.999 seconds.
 1000000
 1234567
 Test Size
 1234567890
 test #0   
       1234 
 */
void printRuntimeTable(functionRuntimes fRT)
{
    int vertical, horizontal;

    printf("\n%s\n", fRT.name);
    printf("Test Size ");

    for (horizontal = 0; horizontal < fRT.numTestCases; horizontal++)
    {
        printf("Test #%-4d", horizontal);
    }

    printf("Average\n");

    for (vertical = 0; vertical < fRT.numTestCaseSizes; vertical++)
    {
        printf("%-10d", fRT.testCaseSizes[vertical]);
        for (horizontal = 0; horizontal < fRT.numTestCases; horizontal++)
        {
            printf("%-10.3lf", fRT.times[vertical][horizontal]);
        }
        printf("%-10.3lf\n", fRT.avg[vertical]);
    }
}

/* TO BE COMPLETED BY YOU
 * Free all of the dynamically allocated memory in fRT
 */
void freeFunctionRuntimes(functionRuntimes fRT)
{

    free(fRT.avg);
    int vertical, horizontal;

    for (vertical = 0; vertical < fRT.numTestCaseSizes; vertical++)
    {
        free(fRT.times[vertical]);
    }
    free(fRT.times);

    double **times;       //run times
    double *avg;          //average runtime
    int numTestCases;     //number of times to repeat each test size
    int numTestCaseSizes; //number of test sizes
    int *testCaseSizes;   //array containing the test sizes
}
