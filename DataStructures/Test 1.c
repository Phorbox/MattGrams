char *ns;
ns = get_digits("(210) 458-7346");
//ns should be pointing to a dynamically created new string "2104587346"
ns = get_digits("abc 458 xyz 7346");
//ns should be pointing to a dynamically created new string "4587346"

char *get_digits(char *str)
{
    int strIndex;
    int numberOfNumbers;
    int numbersIndex;
    char *justNumbers;

    while (str[strIndex] != NULL)
    {
        if (str[strIndex] >= '0' && str[strIndex] <= '9')
        {
            numberOfNumbers++;
        }
    }

    justNumbers = (char *)malloc(sizeof(char) * numberOfNumbers);
    if (justNumbers = NULL)
    {
        exit(-1);
    }

    numbersIndex = 0;
    strIndex = 0;

    while (numbersIndex < numberOfNumbers)
    {
        while (str[strIndex] != NULL)
        {
            if (str[strIndex] >= '0' && str[strIndex] <= '9')
            {
                justNumbers[numbersIndex] = str[strIndex];
            }
            strIndex++;
        }
    }
    char *ns;
}

#include <stdio.h>
typedef struct
{
    int x;
    int y;
} fractionT;

main()
{
    int z[6] = {3, 4, 5, 7, 2, 9};
    int *p1, **p2;
    fractionT f[2];
    p1 = &z[3];
    p2 = &p1;
    *p1-- = 19;
    *--p1 = 18;
    printf("%d %d %d %d %d \n",
           z[0], z[1], z[2], z[3], **p2);

    z[5] = func(&f[1], &f[1].y, &p1);
    printf("%d %d %d %d \n",
           z[3], z[5], f[0].y, f[1].y);
}
int func(fractionT *a, int *b, int **c)
{
    int x = 4, y = 21;
    *b = y / x % 3;
    2 a--;
    f0
        *c = &a->y;
    **c = 7;
    return *b + a->y;
}

int are_all_numbers_unique_and_in_range(int MS[][N])
{
    int i, j;
    int indexI, indexJ;
    int indexValue;

    indexI = 0;
    indexJ = 0;
    indexValue = MS[0][0];
    i = 0;
    j = 1;

    while (indexI < N)
    {
        while (indexJ < N)
        {

            while (i < N)
            {

                while (j < N)
                {

                    if (MS[i][j] > N * N || MS[i][j] < 1 || MS[i][j] == indexValue)
                    {
                        return 0;
                    }

                    j++;
                }
                j = 0;
                i++;
            }
            indexJ++;
            indexValue = MS[indexI][indexJ];
        }
        indexJ = 0;
        indexI++;
    }
}

int f(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if (a == b)
    {
        return f(a - 1, b - 1) + 2*a - 1;
    }

    if (a > b)
    {
        return f(a - b, b) + f(b, b);
    }

    if (a < b)
        return f(a, a) + f(b - a, a);
}
