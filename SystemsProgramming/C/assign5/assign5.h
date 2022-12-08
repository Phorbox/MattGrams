#ifndef ASSIGN5_H
#define ASSIGN5_H

typedef struct
{
    char name[80];
    char schedule[4];
    unsigned hours;
    unsigned size;
    unsigned padding; // unused but required
} COURSE;

const int STRUCTSIZE = sizeof(COURSE);
const char COURSEFILENAME[] = "./courses.dat";
const char FILEPATH[] = "/usr/local/courses/ssilvestro/cs3424/Spring21/assign5/data/courses.dat";

const int NAMEOFFSET = 0;
const int SCHEDULEOFFSET = sizeof(char) * 80;
const int HOUROFFSET = sizeof(char) * 80 + sizeof(char) * 4;
const int SIZEOFFSET = sizeof(char) * 80 + sizeof(char) * 4 + sizeof(unsigned);

const int SIZEOFNAME = sizeof(char) * 80;
const int SIZEOFSCHEDULE = sizeof(char) * 4;
const int SIZEOFHOURS = sizeof(unsigned);
const int SIZEOFSIZE = sizeof(unsigned);
const int UNSIGNEDMAXCHAR = 10;

void printMenu();
void bylinePrint();
void menuChoice(char option);
void menuLoop();

COURSE gatherCourseInfo();
void writeCourse(unsigned courseID, COURSE *newCourse);
unsigned gatherCourseNumber();
void createCourse();
void errChecker(char *action, int errCheck);

unsigned verifyCourse(unsigned courseID);
void updateCourse();
COURSE compareCourse(unsigned courseID, COURSE upCourse);
COURSE pullCourse(unsigned courseID);
void errExit(const char szFmt[], ...);

void readCourse(unsigned courseID);
void printCourse(unsigned courseID, COURSE *myCourse);

void megaCreate();
void megaRead();
void megaDelete();
void megaUpdate();
void deleteCourse(unsigned courseID);

void makeDatFile();
void checkDatFile();

#endif
