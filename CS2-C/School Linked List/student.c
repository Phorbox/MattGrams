
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
typedef enum NodeType
{
    Middle,
    Head,
    Tail
} NodeType;

// Student is a combination of an id, name, age, and gpa
typedef struct Student_struct
{
    int id;
    char name[50];
    double gpa;
} Student;

// LLNodeStudent is a node for a linked list of students
typedef struct LLNodeStudent_struct
{
    Student Student;
    NodeType Type;
    struct LLNodeStudent *Next;

} LLNodeStudent;

LLNodeStudent *createNodeLL(Student s, NodeType type)
{
    LLNodeStudent *node = NULL;
    node = (LLNodeStudent *)malloc(sizeof(LLNodeStudent));
    node->Student = s;
    node->Type = type;
    node->Next = NULL;
    return node;
}

LLNodeStudent *createMiddleLL()
{
    LLNodeStudent *middle = NULL;
    Student s;
    middle = createNodeLL(s, Middle);
    middle->Next = NULL;
    return middle;
}
LLNodeStudent *createTailLL()
{
    LLNodeStudent *tail = NULL;
    Student s;
    tail = createNodeLL(s, Tail);
    tail->Next = NULL;
    return tail;
}
LLNodeStudent *createHeadLL()
{
    LLNodeStudent *head = NULL;
    Student s;
    head = createNodeLL(s, Head);
    head->Next = NULL;
    return head;
}

LLNodeStudent *seedStudentLL()
{

    LLNodeStudent *tail = NULL;
    tail = createTailLL();

    LLNodeStudent *head = NULL;
    head = createHeadLL();

    head->Next = tail;
}

LLNodeStudent *pointToLastNode(LLNodeStudent *head)
{
    LLNodeStudent *current = head;
    while (current->Next->Type != Tail && current->Next != NULL)
    {
        current = current->Next;
    }
    return current;
}

// LLNodeStudent *Append(LLNodeStudent *head, LLNodeStudent *newNode)
// {

//     LLNodeStudent *current = pointToLastNode(head);
//     newNode->Next = current->Next;
//     current->Next = newNode;
//     return head;
// }

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
LLNodeStudent *fillSchool(LLNodeStudent *head, FILE *inputFile)
{
    int tempID;
    char tempName[10];
    double tempGpa;
    char buffer[1000];
    LLNodeStudent *temp;

    int fileLength = getFileLength(inputFile);
    int i = 0;
    while (i < fileLength && !feof(inputFile))
    {
        temp = createMiddleLL();
        fgets(buffer, 1000, inputFile);
        sscanf(buffer, "%d,%50[^,],%lf", &tempID, tempName, &tempGpa);
        temp->Student.id = tempID;
        strcpy(temp->Student.name, tempName);
        temp->Student.gpa = tempGpa;
        alphabeticalPend(head, temp);
        i++;
    }
    return head;
}

LLNodeStudent *bubbleSort(LLNodeStudent *head)
{

    int n = length(head), i = 0;
    for (i = 0; i < n; i++)
    {
        LLNodeStudent *previousNode = NULL;
        LLNodeStudent *currentNode = head;
        LLNodeStudent *followingNode = head->Next; //cur->Next
        while (followingNode != NULL)
        {
            if (currentNode->Student.id > followingNode->Student.id)
            {
                if (currentNode == head)
                {
                    head = followingNode;
                }
                else
                {
                    previousNode->Next = followingNode;
                    currentNode->Next = followingNode->Next;
                    followingNode->Next = currentNode;
                    previousNode = followingNode;
                    followingNode = currentNode->Next;
                }
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->Next;   //suc
                followingNode = currentNode->Next; //suc->Next
            }
        }
    }
    return head;
}

int compareAscii(char *firstString, char *secondString, int i)
{
    if (firstString[i] == secondString[i] && firstString[i] != NULL && secondString[i] != NULL)
    {
        compareAscii(firstString, secondString, i + 1);
    }
    if (firstString[i] > secondString[i] || firstString[i] == NULL)
    {
        return 0;
    }
    if (firstString[i] < secondString[i] || secondString[i] == NULL)
    {
        return 1;
    }
    return -1;
}

void *alphabeticalPend(LLNodeStudent *compareNode, LLNodeStudent *newNode)
{
    LLNodeStudent *currentNode;
    currentNode = compareNode->Next;
    int compare = compareAscii(currentNode, newNode, 0);
    if (compare == 0)
    {
        alphaPend(currentNode, newNode);
    }
    if (compare == 1)
    {
        newNode->Next = currentNode;
        compareNode->Next = newNode;
    }
}

void printList(LLNodeStudent *head)
{
    LLNodeStudent *current;
    current = head->Next;
    while (current->Next != NULL && current->Next->Type != Tail)
    {
        printf("%d, %s, %lf.1", current->Student.id, current->Student.name, current->Student.gpa);
        current = current->Next;
    }
}

void freeList(LLNodeStudent *current)
{
    if (current->Next != NULL && current->Type != Tail)
    {
        freeList(current->Next);
    }
    free(current);
}