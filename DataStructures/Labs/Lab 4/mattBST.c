
#include <stdio.h>
#include "BST.h"

/*
Author: Matthew Henderson
Assignment Number: Lab Assignment 4
File Name: mattBST.c
Course/Section: CS 2123 Section 0D1
Due Date: 11/23/20
Instructor: Dr. Ku
*/

/******************** getHeight **************************************
Purpose:
 * recursively returns the height of a BST
Parameters:
 * nodeT *tree:   the root of the tree
Returns:
 * Height of BST
Notes:
 * Recursive. If given an empty tree it will return 0.
**************************************************************************/
int getHeight(nodeT *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int pLeftHeight = getHeight(tree->pLeft);
    int pRightHeight = getHeight(tree->pRight);
    
    if (pLeftHeight >= pRightHeight)
    {
        return pLeftHeight + 1;
    }
    else
    {
        return pRightHeight + 1;
    }

    return -999;
}
/******************** printHeight **************************************
Purpose:
 * prints the height of a BST
Parameters:
 * nodeT *tree:   the root of the tree
Returns:
 *Void
Notes:
 * Recursive. If given an empty tree it will print -1.
**************************************************************************/

void printHeight(nodeT *tree)
{
    int height = -1;
    height += getHeight(tree);
    printf("The height is %d.\n", height);
}

/******************** getNumberOfNodes **************************************
Purpose:
 * recursively will return the number of nodes in BST
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * returns the number of nodes in a BST
Notes:
 * Recursive. If given an empty tree it will return 0.
**************************************************************************/
int getNumberOfNodes(nodeT *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return getNumberOfNodes(tree->pLeft) + getNumberOfNodes(tree->pRight) + 1;
}

/******************** printNNodes **************************************
Purpose:
 * prints  the number of nodes in BST
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * void
Notes:
 * Recursive. If given an empty tree it will print 0.
**************************************************************************/
void printNNodes(nodeT *tree)
{
    int numberOfNodes = 0;
    numberOfNodes += getNumberOfNodes(tree);
    printf("The number of nodes is %d.\n", numberOfNodes);
}

/******************** getNumberOfLeaves **************************************
Purpose:
 * recursively will return the number of nodes in BST
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * returns the value of the number of leaves in a BST
Notes:
 * Recursive. If given an empty tree it will return 0.
**************************************************************************/
int getNumberOfLeaves(nodeT *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    if(((tree->pLeft) == NULL) && (tree->pRight) == NULL)
    {
        return 1;
    }
    return getNumberOfLeaves(tree->pLeft) + getNumberOfLeaves(tree->pRight);
}

/******************** printNLeaves **************************************
Purpose:
 * prints number of leaves in a bst by calling getNumberOfLeaves
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * void
Notes:
 * Recursive. If given an empty tree it will return 0.
**************************************************************************/
void printNLeaves(nodeT *tree)
{
    int numberOfLeaves = 0;
    numberOfLeaves += getNumberOfLeaves(tree);
    printf("The number of leaves is %d.\n", numberOfLeaves);
}

/******************** printPreOrder **************************************
Purpose:
 * Prints the tree's values in preorder
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * N/A
Notes:
 * Recursive. If given an empty tree it will do nothing.
**************************************************************************/
void printPreOrder(nodeT *tree)
{
    if (tree == NULL)
        return;
    printf("%d ", tree->value);
    printPreOrder(tree->pLeft);
    printPreOrder(tree->pRight);
}

/******************** printPostOrder **************************************
Purpose:
 * Prints the tree's values in postorder
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * N/A
Notes:
 * Recursive. If given an empty tree it will do nothing.
**************************************************************************/
void printPostOrder(nodeT *tree)
{
    if (tree == NULL)
        return;
    printPostOrder(tree->pLeft);
    printPostOrder(tree->pRight);
    printf("%d ", tree->value);
}


/******************** printAfterInsert **************************************
Purpose:
 * makes sure there is no null tree before print a BST in different orders
Parameters:
 * nodeT *tree: the root of the tree
Returns:
 * N/A
Notes:
 * Recursive. If given an empty tree it will do nothing.
**************************************************************************/
printAfterInsert(nodeT *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printHeight(tree);
        printNNodes(tree);
        printNLeaves(tree);
        printf("\n");
    }
}