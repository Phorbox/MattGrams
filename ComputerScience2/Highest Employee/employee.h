#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct Employee_struct
{
    char name[20];
    int id;
    double salary;
} Employee;

int getFileLength(char *fileName);
Employee *getFileContent(char *fileName, int length);
int checkFileOpening(FILE *inFile);
void getEmployeeWithHigestSalary(Employee *company, int length, char *outFileName);

#endif