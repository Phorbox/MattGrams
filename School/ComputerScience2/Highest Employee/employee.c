#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Employee_struct
{
    char name[20];
    int id;
    double salary;
} Employee;


int getFileLength(char *fileName)
{
    //creates file pointer
    int output;
    FILE *inFile;
    inFile = fopen(fileName, "r");
    output = checkFileOpening(inFile);

    //counts the number of lines
    char buffer[1000];
    while (!feof(inFile) && output != -1)
    {
        fgets(buffer, 1000, inFile);
        output++;
    }
    fclose(inFile);
    return output;
}

Employee *getFileContent(char *fileName, int length)
{
    FILE *inFile;

    inFile = fopen(fileName, "r");

    int check;
    check = checkFileOpening(fileName);

    Employee *company = (Employee *)malloc(sizeof(Employee) * length);
    char name[20];
    int id;
    double salary;
    int i = 0;
    char buffer[1000];

    while (!feof(inFile) && i < length && check != -1)
    {
        //stores the next line of file to buffer
        fgets(buffer, 1000, inFile);

        //seperates buffer into the data that is being looked for
        sscanf(buffer, "%s %d %lf", name, &id, &salary);

        //fills the employee array with content
        strcpy(company[i].name, name);
        company[i].id = id;
        company[i].salary = salary;

        i++;
    }
    fclose(inFile);
    return company;
}

int checkFileOpening(FILE *inFile)
{
    //if the file does not open properly output = 1
    int output = 0;

    if (inFile == NULL)
    {
        printf("Error\n");
        output = -1;
    }
    return output;
}

void getEmployeeWithHigestSalary(Employee *company, int length, char *outFileName)
{
    /* this function will create a file with the highest salary employees,
    if there are multiple highest, all will be stored in the file*/

    int i = 0;
    int j = 0;
    //best is an array of the indeces of company that are highest salary
    int *best = (int *)malloc(sizeof(int) * length);
    //highest is highest salary
    double highest = 0.0;
    for (i = 0; i < length; i++)
    {
        /*if the salary is greater than highest, it clears the list of
        highest and begins a new list, if it is equal, it populates
        best with the next value*/
        if (company[i].salary > highest)
        {
            
            for(j = length - 1; j > 0; j--)
            {
                
                best[j] = length+1;
            }

            highest = company[i].salary;
            best[0] = i;
            j = 1;
        }
        else if (company[i].salary == highest)
        {
            best[j] = i;
            j++;
        }
    }

    //write to a new file the highest salaried employees
    FILE *outFile;
    outFile = fopen(outFileName, "w");
    int check = checkFileOpening(outFile);
    i = j-1;
    
    char name[20];
    int id;
    double salary;
    while (i >= 0 && check != -1)
    {
        j = best[i];
        strcpy(name, company[j].name);
        id = company[j].id;
        salary = company[j].salary;
        fprintf(outFile, "%s %d %.2lf\n", name, id, salary);
        i--;
    }
    free(best);
    fclose(outFile);
}
