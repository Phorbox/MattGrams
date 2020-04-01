#include <stdio.h>

//Adds a value to the running total
void calcAdd(double *running, double operating)
{
    *running += operating;
}

//Subracts a value from the running total
void calcSubtract(double *running, double operating)
{
    *running -= operating;
}

//Multiplies a value with the running total
double calcMultiply(double running, double operating)
{
    running *= operating;
    return running;
}

//Divides a value from the running total
double calcDivide(double running, double operating)
{
    running /= operating;
    return running;
}

//Main Calculator Function
void calculator()
{
    int looping = 1;
    int choosing = 5;
    double running = 0;
    double operating = 0;

    while (looping == 1)
    {
        //Gets a valid operator from user.
        choosing = 5;
        while (choosing != 1 && choosing != 2 && choosing != 3 && choosing != 4 && choosing != 0)
        {
            printf("\nWhat operation to perform?\n1: Add\n2: Subtract\n3: Multiply\n4: Division\n0: Exit\n");
            scanf("%d", &choosing);
        }
        //If the user does not exit, asks for a value.
        if (choosing != 0)
        {
            printf("What value to operate?\n");
            scanf("%lf", &operating);
            switch (choosing)
            {
            case 1: //add
                calcAdd(&running, operating);
                break;
            case 2: //subtract
                calcSubtract(&running, operating);
                break;
            case 3: //multiply
                running = calcMultiply(running, operating);
                break;
            case 4: //divide
                running = calcDivide(running, operating);
                break;
            default:
                looping = 0;
                break;
            }
            printf("Your total: \n%lf\n", running);
        }
        else
        {
            looping = 0;
        }
    }
}
