#ifndef MATTSTACK_H
#define MATTSTACK_H

typedef struct mattStack
{
    int stack[1000];
    int Head;
} mattStack;

void push(mattStack *stack, int value);
int pop(mattStack *stack);

#endif