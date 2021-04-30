

#include <stdio.h>
#include <stdlib.h>
#include "postFix.h"

void readTape(char *tape, postfixStack *postfixStack)
{
    int head = 0;
    printf("%s",tape);
    do
    {

        if (isDigit(tape[head]))
        {
            integerPush(tape[head], postfixStack);
        }
        else if (isOperator(tape[head]))
        {
            operatorPop(tape[head], postfixStack);
        }
        else if (isNotUseful(tape[head]))
        {
            if(isUseful(tape[head+1])){
                 printf("Error: There is an unrecognizable character, only single digit numerals and the basic math operators, and the space character are permitted.\n\n");
            return;
            }
        }
        head++;
    } while (tape[head] != '\0' && (postfixStack->stackIndex) != 0);

    if ((postfixStack->stackIndex) != 0)
    {
        int printInt = (postfixStack->stack)[0];
        // (postfixStack->stack)[0] = NULL;
        printf("Your total is: %d\n\n", printInt);
        (postfixStack->stack)[0] = 0;
    }
    else
    {
        printf("Error: There are too many operations to values, the stack is underloaded! remove some operators or add more values\n\n");
    }
}

void integerPush(char insert, postfixStack *postfixStack)
{
    int toPush = charToInt(insert);
    int tempIndex = (postfixStack->stackIndex);
    (postfixStack->stack)[tempIndex] = toPush;
    (postfixStack->stackIndex)++;
}

int charToInt(char input)
{
    int convert;
    if (isDigit(input))
    {
        convert = (int)(input) - (int)('0');
    }
    else
    {
        printf("Error: Can only convert single digit integer characters into int data type.\n\n");
        convert = -1;
    }

    return convert;
}

void operatorPop(char operand, postfixStack *postfixStack)
{
    int trailingNumber = pop(postfixStack);
    int tempIndex = (postfixStack->stackIndex);

    if (isOperator(operand))
    {

        switch (operand)
        {
        case '+':
            (postfixStack->stack)[(tempIndex)-1] += trailingNumber;
            break;

        case '-':

            (postfixStack->stack)[(tempIndex)-1] -= trailingNumber;
            break;

        case '*':

            (postfixStack->stack)[(tempIndex)-1] *= trailingNumber;
            break;

        case '/':

            (postfixStack->stack)[(tempIndex)-1] /= trailingNumber;
            break;

        default:
            break;
        }
    }
    else
    {
        printf("Error: Can only use mathmatical operators\n\n");
    }
}

int pop(postfixStack *postfixStack)
{
    int output;

    (postfixStack->stackIndex)--;
    output = (postfixStack->stack)[(postfixStack->stackIndex)];
    // (postfixStack->stack)[(postfixStack->stackIndex)] = NULL;

    return output;
}

int isOperator(char op)
{
    if ((op == '+') || (op == '-') || (op == '*') || (op == '/'))
    {
        return 1;
    }
    return 0;
}

int isDigit(char op)
{
    if (
        (op == '0') || (op == '1') || (op == '2') || (op == '3') || (op == '4') || (op == '5') || (op == '6') || (op == '7') || (op == '8') || (op == '9'))
    {
        return 1;
    }
    return 0;
}

int isNotUseful(char op)
{
    if (
        (op == '0') || (op == '1') || (op == '2') || (op == '3') || (op == '4') || (op == '5') || (op == '6') || (op == '7') || (op == '8') || (op == '9') || (op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == ' '))
    {
        return 0;
    }
    return 1;
}
int isUseful(char op)
{
    if (
        (op == '0') || (op == '1') || (op == '2') || (op == '3') || (op == '4') || (op == '5') || (op == '6') || (op == '7') || (op == '8') || (op == '9') || (op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == ' '))
    {
        return 1;
    }
    return 0;
}