

#include <stdio.h>
int recursivePower(int n1, int n2);
int main()
{
    int base, exponent, result;
    printf("This function evaluates a number to its a power.\n (Thus multiplying it by itself a number of times equal to the power)\n\nWhat is the Base?: ");
    scanf("%d", &base);
    do
    {
        printf("What is the power(positive integers only): ");
        scanf("%d", &exponent);
    } while (exponent < 0);

    result = recursivePower(base, exponent);
    printf("%d^%d = %d", base, exponent, result);
    return 0;
}

int recursivePower(int base, int exponent)
{
    if (exponent != 0)
        return (base * recursivePower(base, exponent - 1));
    else
        return 1;
}