#ifndef STUDENT_H
#define STUDENT_H
typedef struct Student_struct
{
 int id;
 char name[10];
 int age;
 double gpa;
} Student;

int checkFileOpening(FILE *inputFile);
int getFileLength(FILE *inputFile);
void fillSchool(Student *school, FILE *inputFile);
void mergeSort(Student *school, int lowerIndex, int higherIndex);
void merge(Student *school, int lowerIndex, int middleIndex, int higherIndex);
int binarySearch(Student *school, int length, int searchValue);

#endif