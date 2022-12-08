
#include <stdio.h>
#include "mattStack.h"

#define mattStackMax (1000)


typedef struct mattStack
{
    int stack[mattStackMax];
    int Head;
} mattStack;

void push(mattStack *stack, int value)
{
    if (stack->Head >= (mattStackMax - 1)){
        printf("Error, The stack is full, maximum limit is 1000");
        return;
    }
    (stack->stack)[stack->Head] = value;
    (stack->Head)++;
    
}

int pop(mattStack *stack)
{
    if (stack->Head <= 0){
        printf("Error, The stack is empty, there should be no value at %d", stack->Head);
        return;
    }
    int value = (stack->stack)[stack->Head];
    (stack->Head)--;

    return value;
}


void inorderTransversal(nodeT *tree, mattStack *stack)
{
    if ((*tree).value == NULL)
    {
        return;
    }
    push(stack, tree->value);
    inorderTransversal(tree->pLeft, stack);
    inorderTransversal(tree->pRight, stack);
}

void preorderTransversal(nodeT *tree, mattStack *stack)
{
    if ((*tree).value == NULL)
    {
        return;
    }
    inorderTransversal(tree->pLeft, stack);
    push(stack, tree->value);
    inorderTransversal(tree->pRight, stack);
    t
}

void postorderTransversal(nodeT *tree, mattStack *stack)
{
    if ((*tree).value == NULL)
    {
        return;
    }
    inorderTransversal(tree->pLeft, stack);
    inorderTransversal(tree->pRight, stack);
    push(stack, tree->value);
}

void printTraversal(mattStack *stack)
{
    int i;
    for (i = 0, i < (stack->Head), i++)
    {
        printf("%d ", (stack->stack)[i]);
    }
    printf("\n");
}

void printBst(nodeT *tree)
{
    if (tree->value != NULL)
    {
        printf("BST is not empty\n");
    }
    else
    {
        return;
    }

    mattStack bstContents;
    bstContents.Head = 0;
    int total = getNumberOfNodes(tree);

    inorderTransversal(tree, &bstContents);
    printf("Inorder Traversal of BST: \n");
    printTraversal(&bstContents);
    bstContents.Head = 0;

    preorderTransversal(tree, &bstContents);
    printf("Preorder Traversal of BST: \n");
    printTraversal(&bstContents);
    bstContents.Head = 0;

    postorderTransversal(tree, &bstContents);
    printf("Postorder Traversal of BST: \n");
    printTraversal(&bstContents);
    bstContents.Head = 0;
}