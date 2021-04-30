#ifndef STUDENT_H
#define STUDENT_H

typedef enum NodeType
{
    Middle,
    Head,
    Tail
} NodeType;

typedef struct Student_struct
{
    int id;
    char name[50];
    double gpa;
} Student;

typedef struct LLNodeStudent_struct
{
    Student Student;
    NodeType Type;
    struct LLNodeStudent *Next;

} LLNodeStudent;

LLNodeStudent *createNodeLL(Student s, NodeType type);
LLNodeStudent *createMiddleLL();
LLNodeStudent *createTailLL();
LLNodeStudent *createHeadLL();
LLNodeStudent *seedStudentLL();
LLNodeStudent *pointToLastNode(LLNodeStudent *head);
LLNodeStudent *Append(LLNodeStudent *head, LLNodeStudent *newNode);
int checkFileOpening(FILE *inputFile);
int getFileLength(FILE *inputFile);
LLNodeStudent *fillSchool(LLNodeStudent *head, FILE *inputFile);
LLNodeStudent *bubbleSort(LLNodeStudent *head);
int compareAscii(char *firstString, char *secondString, int i);
void *alphabeticalPend(LLNodeStudent *compareNode, LLNodeStudent *newNode);
void printList(LLNodeStudent *head);
void freeList(LLNodeStudent *current);


#endif