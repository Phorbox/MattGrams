#include <stdio.h>
#include <stdlib.h>

void pascTriangle(int height);

int main(int argc, char *argv[])
{
	int height;

	//forces the user to input a value that works with pascal's triangle, so 1 or greater.
	do
	{
		printf("How many rows of pascal's triangle to print?\n");
		scanf("%d", &height);
		if (height < 1)
		{
			printf("You cant choose a number less than 1!\n");
		}
	} while (height < 1);
	printf("\n");

	pascTriangle(height);

	return 0;
}

//pascTriangle takes an int parameter of height and prints a pascal's triangle to that height, the function is void and doesnt output.
void pascTriangle(int height)
{
	//arrays to represent the previous row to do the math for the next row
	int *previous;
	int *current;
	previous = (int *)malloc(height * sizeof(int));
	current = (int *)malloc(height * sizeof(int));

	//increment variables
	int y;
	int x;

	//each increment of x is a new row
	for (x = 0; x < height; x++)
	{
		//fills 1's at beginning and end of rows
		current[0] = 1;
		current[x] = 1;

		//fill current from [1] to [x-1]
		y = 1;
		while (y < x)
		{
			current[y] = previous[y] + previous[y - 1];
			y++;
		}

		//spaces before each row to make an isosceles triangle
		for (y = height - x; y > 0; y--)
		{
			printf(" ");
		}

		// prints the row that contains current's values
		y = 0;
		do
		{
			printf("%d ", current[y]);
			y++;
		} while (y <= x);

		//new line for next row
		printf("\n");

		//sets current row as next rows operator values
		for (y = 0; y <= height; y++)
		{
			previous[y] = current[y];
			current[y] = 0;
		}
	}
}
