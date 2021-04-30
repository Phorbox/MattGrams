
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Student is a combination of an id, name, age, and gpa
typedef struct Student_struct
{
    int id;
    char name[10];
    int age;
    double gpa;
} Student;

// checkFileOpening returns -1 if inputFile opened improperly, and 0 otherwise
int checkFileOpening(FILE *inputFile)
{
    int output = 0;

    if (inputFile == NULL)
    {
        printf("Error\n");
        output = -1;
    }
    return output;
}


// getFileLength returns an int of the length of fileName
int getFileLength(FILE *inputFile)
{
    int output = 0;
    char buffer[1000];
    while (!feof(inputFile))
    {
        fgets(buffer, 1000, inputFile);
        output++;
    }
    rewind(inputFile);
    return output;
}

// fillSchool returns the file length
void fillSchool(Student *school, FILE *inputFile)
{
    int tempID;
    char tempName[10];
    int tempAge;
    double tempGpa;

    char buffer[1000];

    int fileLength = getFileLength(inputFile);
    int i = 0;
    while (i < fileLength && !feof(inputFile))
    {
        fgets(buffer, 1000, inputFile);
        sscanf(buffer, "%d,%10[^,],%d,%lf", &tempID, tempName, &tempAge, &tempGpa);
        school[i].id = tempID;
        strcpy(school[i].name, tempName);
        school[i].age = tempAge;
        school[i].gpa = tempGpa;
        i++;
    }
}

// merge combine two arrays and sort them. It needs an array of students, a lower index, a middle index, and a higher index
void merge(Student *school, int lowerIndex, int middleIndex, int higherIndex)
{
    int length = higherIndex - lowerIndex + 1;
    Student *temp;
    temp = (Student *)malloc(length * sizeof(Student));

    int t = 0;
    int left = lowerIndex;
    int right = middleIndex + 1;

    while (left <= middleIndex && right <= higherIndex)
    {
        if (school[left].id <= school[right].id)
        {
            temp[t] = school[left];
            t++;
            left++;
        }
        else
        {
            temp[t] = school[right];
            t++;
            right++;
        }
    }
    while (left <= middleIndex)
    {
        temp[t] = school[left];
        t++;
        left++;
    }
    while (right <= higherIndex)
    {
        temp[t] = school[right];
        t++;
        right++;
    }
    for (t = 0; t < length; t++)
    {
        school[lowerIndex + t] = temp[t];
    }
    free(temp);
}

//mergeSort recursivly breaks up an array of students or calls merge when it cannot anymore
void mergeSort(Student *school, int lowerIndex, int higherIndex)
{
    if (lowerIndex < higherIndex)
    {
        int middleIndex = (lowerIndex + higherIndex) / 2;
        // Sort the left half
        mergeSort(school, lowerIndex, middleIndex);
        // Sort the right half
        mergeSort(school, middleIndex + 1, higherIndex);
        // Merge the halves
        merge(school, lowerIndex, middleIndex, higherIndex);
    }
}
//binarySearch returns the index of a student in an array whose id matches the search value
int binarySearch(Student *school, int length, int searchValue)
{
    int mid;
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (school[mid].id == searchValue)
        {
            return mid;
        }
        else if (school[mid].id > searchValue)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
