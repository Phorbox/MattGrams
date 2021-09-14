/*
Author: Matthew Henderson
Assignment Number: Lab Assignment 4
File Name: driver.c
Course/Section: CS 2123 Section 0D1
Due Date: 11/23/20
Instructor: Dr. Ku
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BST.h"
#include "mattBST.h"

/*
 *
 */
int main(int argc, char **argv)
{
    printf("Constructing empty BST.\n");
    nodeT *pRoot = NULL; //root
    int data;            //holds the int data
    printf("\nBST is empty.\n");
    printHeight(pRoot);
    printNNodes(pRoot);
    printNLeaves(pRoot);

    //Insertion of new items, reports when done
    printf("Items to insert (-999 to stop): ");
    scanf("%d", &data);

    while (data != -999)
    {
        pRoot = insert(pRoot, data);
        printAfterInsert(pRoot);
        printf("Items to insert (-999 to stop): ");
        scanf("%d", &data);
    }
    report(pRoot);

    //deletion of items, reports after each deletion
    printf("Items to delete (-999 to stop): ");
    scanf("%d", &data);
    while (data != -999)
    {
        pRoot = deleteNode(pRoot, data);
        report(pRoot);
        printf("Items to delete (-999 to stop): ");
        scanf("%d", &data);
        printHeight(pRoot);
        printNNodes(pRoot);
        printNLeaves(pRoot);
    }

    return 0;
}
