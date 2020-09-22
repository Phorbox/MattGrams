
#include <stdio.h>

int main()
{
    int block;
    int ascending;
    int descending;
    int tens;
    int ones;
    int height = 9;
    int width = 10;

    for (int block = 0; block < height; block++)
    {
        tens = block + 1;
        if (block % 2 == 0)
        {
            ones = 0;
            for (int ascending = 0; ascending < width; ascending++)
            {
                printf("%d%d ", tens, ones);
                ones++;
            }
        }
        if (block % 2 == 1)
        {
            ones = 9;
            for (int descending = 0; descending < width; descending++)
            {
                printf("%d%d ", tens, ones);
                ones--;
            }
        }
        printf("\n");
    }

    return 0;
}
