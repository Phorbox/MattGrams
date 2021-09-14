#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Student is a combination of an id, name, age, and gpa
typedef struct IntNode_struct
{
    int Value;
    IntNode *Next;
    // node *previous;
} IntNode;

//assumes length of binary list is known
int LLBinarySearch(IntNode *List, int ListMin, int ListMax, int SearchKey)
{
    IntNode CurrentNode = List[0];
    IntNode NextNode;

    int Middle = ListMin + ListMax / 2;
    int i;
    for (i = 0; i < Middle; i++)
    {
        CurrentNode = NextNode;
        NextNode = *(CurrentNode.Next);
    }
    if (SearchKey == CurrentNode.Value)
    {
        return CurrentNode.Value;
    }
    if (CurrentNode.Value > SearchKey)
    {
        return LLBinarySearch(List, ListMin, Middle, SearchKey);
    }
    if (CurrentNode.Value < SearchKey)
    {
        return LLBinarySearch(List, Middle, ListMax, SearchKey);
    }
    return -1;
}

void StartLLBinarySearch()
{
}

IntNode *MakeList(int *IntArray, int ArrayLength)
{
    IntNode *LinkedList;
    LinkedList = (IntNode *)malloc((ArrayLength + 2) * sizeof(IntNode));
    //Head
    LinkedList[0].Next = &LinkedList[1];
    //Tail
    LinkedList[1];
    return LinkedList;
}