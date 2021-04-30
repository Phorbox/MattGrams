#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include "assign5.h"

#include <stdarg.h>
#define ERROR_PROCESSING 99

int main(int argc, char *argv[])
{
    bylinePrint();
    menuLoop();
}

void printMenu()
{
    printf("Enter one of the following actions or type CTRL-D to exit.\n");
    printf("C - create a new course record\n");
    printf("R - read an existing course record\n");
    printf("U - update an existing course record\n");
    printf("D - delete an existing course record\n");
}

void bylinePrint()
{
    printf("Assignment 5 created by Matthew Henderson (rmt564)\n\n");
}

void menuChoice(char option)
{
    option = tolower(option);
    switch (option)
    {
    case 'c':
        megaCreate();
        break;
    case 'r':
        megaRead();
        break;
    case 'u':
        megaUpdate();
        break;
    case 'd':
        megaDelete();
        break;
    default:
        printf("no options match '%c'\n", option);
        break;
    }
}
void megaCreate()
{
    unsigned courseID = gatherCourseNumber();
    unsigned test = verifyCourse(courseID);
    if (test != 0)
    {
        printf("ERROR: course already exists\n\n");
        return;
    }

    createCourse(courseID);
}
void megaRead()
{
    unsigned courseID = gatherCourseNumber();
    unsigned test = verifyCourse(courseID);
    if (test == 0)
    {
        printf("ERROR: course not found\n\n");
        return;
    }
    readCourse(courseID);
}
void megaDelete()
{
    unsigned courseID = gatherCourseNumber();
    unsigned test = verifyCourse(courseID);
    if (test == 0)
    {
        printf("ERROR: course not found\n\n");
        return;
    }
    deleteCourse(courseID);
}
void deleteCourse(unsigned courseID)
{

    COURSE toDelete = pullCourse(courseID);
    toDelete.hours = 0;
    writeCourse(courseID, &toDelete);
}

void megaUpdate()
{
    unsigned courseID = gatherCourseNumber();
    unsigned test = verifyCourse(courseID);
    if (test == 0)
    {
        printf("ERROR: course not found\n\n");
        return;
    }
    updateCourse(courseID);
}

void menuLoop()
{
    int exit = 0;
    char buff[50];
    do
    {
        printMenu();
        if (fgets(buff, 10, stdin) == NULL)
        {
            printf("Terminating\n\n");
            return;
        }
        menuChoice(buff[0]);
    } while (exit == 0);
}

COURSE gatherCourseInfo()
{
    COURSE newCourse;
    char buff[81];
    char smallBuff[5];
    char numberBuff[11];
    char *tempStr = NULL;
    tempStr = (char *)malloc(SIZEOFNAME + 1);

    memset(buff, '\0', SIZEOFNAME);
    printf("Enter a course name: ");
    fgets(buff, SIZEOFNAME + 1, stdin);
    buff[SIZEOFNAME + 1] = '\0';
    sscanf(buff, "%s", tempStr);
    strcpy(newCourse.name, tempStr);

    tempStr = (char *)realloc(tempStr, SIZEOFSCHEDULE);
    memset(smallBuff, '\0', SIZEOFSCHEDULE);
    printf("Enter a course schedule: ");
    fgets(smallBuff, SIZEOFSCHEDULE + 1, stdin);
    smallBuff[SIZEOFNAME + 1] = '\0';
    sscanf(smallBuff, "%s", tempStr);
    strcpy(newCourse.schedule, tempStr);

    tempStr = (char *)realloc(tempStr, UNSIGNEDMAXCHAR * sizeof(char));
    char *trash;
    unsigned tempInt = 0;
    printf("Enter course credit hours: ");
    fgets(numberBuff, UNSIGNEDMAXCHAR + 1, stdin);
    numberBuff[SIZEOFNAME + 1] = '\0';
    sscanf(numberBuff, "%s", tempStr);
    tempInt = strtoul(tempStr, &trash, 16);
    newCourse.hours = tempInt;

    tempStr = (char *)realloc(tempStr, UNSIGNEDMAXCHAR * sizeof(char));
    tempInt = 0;
    printf("Enter student enrollment: ");
    fgets(numberBuff, UNSIGNEDMAXCHAR + 1, stdin);
    numberBuff[SIZEOFNAME + 1] = '\0';
    sscanf(numberBuff, "%s", tempStr);
    tempInt = strtoul(tempStr, &trash, 16);
    newCourse.size = tempInt;

    free(tempStr);
    printf("\n");
    return newCourse;
}

void writeCourse(unsigned courseID, COURSE *newCourse)
{
    int MyCourseFile = open(COURSEFILENAME, O_RDWR);
    int seekOffset;
    if (MyCourseFile < 0)
    {
        errExit("Open file for read: %s", strerror(errno));
    }
    int structOffset = courseID * STRUCTSIZE;

    seekOffset = structOffset + NAMEOFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    write(MyCourseFile, newCourse->name, SIZEOFNAME);

    seekOffset = structOffset + SCHEDULEOFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    write(MyCourseFile, newCourse->schedule, SIZEOFSCHEDULE);

    char hex[4];
    memset(hex, '0', SIZEOFHOURS);
    sprintf(hex, "%x", newCourse->hours);
    seekOffset = structOffset + HOUROFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    write(MyCourseFile, hex, SIZEOFHOURS);

    memset(hex, '0', SIZEOFSIZE);
    sprintf(hex, "%x", newCourse->size);
    seekOffset = structOffset + SIZEOFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    write(MyCourseFile, hex, SIZEOFSIZE);

    close(MyCourseFile);
}

unsigned gatherCourseNumber()
{
    char buff[100];
    COURSE newCourse;
    printf("\nEnter a course number: ");
    fgets(buff, 10, stdin);
    unsigned courseID = atoi(buff);
    return courseID;
}

void createCourse(unsigned courseID)
{
    int checker = verifyCourse(courseID);
    if (checker != 0)
    {
        printf("\nERROR: course already exists\n");
        return;
    }
    COURSE newCourse = gatherCourseInfo();
    writeCourse(courseID, &newCourse);
}

//returns the number of hours in a course, 0 will mean that a course is non existent
unsigned verifyCourse(unsigned courseID)
{
    int MyCourseFile = open(COURSEFILENAME, O_RDWR);
    int errCheck = MyCourseFile;
    int seekOffset;
    char hoursBuffer[4];
    unsigned output;

    errChecker("open", errCheck);

    seekOffset = (courseID * STRUCTSIZE);
    seekOffset += HOUROFFSET;

    errCheck = lseek(MyCourseFile, seekOffset, SEEK_SET);
    errChecker("seek", errCheck);

    errCheck = read(MyCourseFile, hoursBuffer, SIZEOFHOURS);
    errChecker("read", errCheck);

    char *trash;
    output = strtoul(hoursBuffer, &trash, 16);
    close(MyCourseFile);
    return output;
}

void errChecker(char *action, int errCheck)
{
    if (errCheck < 0)
    {
        errExit("Bad file %s: %s", action, strerror(errno));
    }
}

void updateCourse(unsigned courseID)
{
    if (verifyCourse(courseID) == 0)
    {
        printf("ERROR: course not found");
        return;
    }
    COURSE upCourse;
    upCourse = gatherCourseInfo();
    upCourse = compareCourse(courseID, upCourse);
    writeCourse(courseID, &upCourse);
}

COURSE compareCourse(unsigned courseID, COURSE upCourse)
{
    COURSE sourceCourse = pullCourse(courseID);
    if ((upCourse.name)[0] == '\0')
    {
        strcpy(upCourse.name, sourceCourse.name);
    }
    sourceCourse = pullCourse(courseID);
    if ((upCourse.schedule)[0] == '\0')
    {
        strcpy(upCourse.schedule, sourceCourse.schedule);
    }
    sourceCourse = pullCourse(courseID);
    if (upCourse.hours == 0)
    {
        upCourse.hours = sourceCourse.hours;
    }
    sourceCourse = pullCourse(courseID);
    if (upCourse.name == 0)
    {
        upCourse.size = sourceCourse.size;
    }
    return upCourse;
}

COURSE pullCourse(unsigned courseID)
{
    COURSE myCourse;
    int MyCourseFile = open(COURSEFILENAME, O_RDWR);
    if (MyCourseFile < 0)
    {
        errExit("Open file for read: %s", strerror(errno));
    }

    int seekOffset;
    char buff[81];
    char smallBuff[5];
    char numberBuff[11];

    int structOffset = courseID * STRUCTSIZE;
    char *tempStr = NULL;
    tempStr = (char *)malloc(SIZEOFNAME + 1);

    memset(buff, '\0', SIZEOFNAME);
    seekOffset = structOffset + NAMEOFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    read(MyCourseFile, buff, SIZEOFNAME);
    buff[SIZEOFNAME + 1] = '\0';
    sscanf(buff, "%s", tempStr);
    strcpy(myCourse.name, tempStr);

    tempStr = (char *)realloc(tempStr, SIZEOFSCHEDULE);
    memset(smallBuff, '\0', SIZEOFSCHEDULE);
    seekOffset = structOffset + SCHEDULEOFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    read(MyCourseFile, smallBuff, SIZEOFSCHEDULE);
    smallBuff[SIZEOFNAME + 1] = '\0';
    sscanf(smallBuff, "%s", tempStr);
    strcpy(myCourse.schedule, tempStr);

    tempStr = (char *)realloc(tempStr, UNSIGNEDMAXCHAR * sizeof(char));
    char *trash;
    unsigned tempInt = 0;
    seekOffset = structOffset + HOUROFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    read(MyCourseFile, numberBuff, SIZEOFHOURS);
    numberBuff[SIZEOFNAME + 1] = '\0';
    sscanf(numberBuff, "%s", tempStr);
    tempInt = strtoul(tempStr, &trash, 16);
    myCourse.hours = tempInt;

    tempStr = (char *)realloc(tempStr, UNSIGNEDMAXCHAR * sizeof(char));
    tempInt = 0;
    seekOffset = structOffset + SIZEOFFSET;
    lseek(MyCourseFile, seekOffset, SEEK_SET);
    read(MyCourseFile, numberBuff, SIZEOFSIZE);
    numberBuff[SIZEOFNAME + 1] = '\0';
    sscanf(numberBuff, "%s", tempStr);
    tempInt = strtoul(tempStr, &trash, 16);
    myCourse.size = tempInt;

    close(MyCourseFile);
    free(tempStr);
    return myCourse;
}

void errExit(const char szFmt[], ...)
{
    va_list args;          // This is the standard C variable argument list type
    va_start(args, szFmt); // This tells the compiler where the variable arguments
                           // begins.  They begin after szFmt.
    printf("ERROR: ");
    vprintf(szFmt, args); // vprintf receives a printf format string and  a
                          // va_list argument
    va_end(args);         // let the C environment know we are finished with the
                          // va_list argument
    printf("\n");
    exit(ERROR_PROCESSING);
}

void readCourse(unsigned courseID)
{
    COURSE myCourse;
    myCourse = pullCourse(courseID);
    printCourse(courseID, &myCourse);
}

void printCourse(unsigned courseID, COURSE *myCourse)
{
    printf("Course number : %i\n", courseID);
    printf("Course name : %s\n", myCourse->name);
    printf("Scheduled days : %s\n", myCourse->schedule);
    printf("Credit hours : %i\n", myCourse->hours);
    printf("Enrolled Students : %i\n\n", myCourse->size);
}

// void makeDatFile(char *infilename, char *outfileDir)
// {
//     FILE *sourceFile; //File handles for source and destination.
//     sourceFile = fopen(FILEPATH, "r");
//     FILE *newFile;
//     newFile = fopen("courses.dat", "w");

//     if (sourceFile == NULL)
//     {
//         printf("Error!");
//         exit(1);
//     }

//     if (newFile == NULL)
//     {
//         printf("Error!");
//         exit(1);
//     }

//     while (!feof(inputFile) && output != -1)
//     {
//         fgets(buffer, 1000, inputFile);
//         output++;
//     }
// }