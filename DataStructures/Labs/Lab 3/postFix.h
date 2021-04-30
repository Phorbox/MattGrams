#ifndef POSTFIX_H
#define POSTFIX_H


typedef struct postfixStack
{
    int stack[50];
    int stackIndex;
} postfixStack;

void integerPush(char insert, postfixStack *postfixStack);
int charToInt(char input);
int pop(postfixStack *postfixStack);
void operatorPop(char operand, postfixStack *postfixStack);
void readTape(char *tape, postfixStack *postfixStack);
int isOperator(char op);
int isDigit(char digit);
int isNotUseful(char op);
int isUseful(char op);


#endif