#include <stdio.h>
#include "dataSetOperations.h"

/*LabAssignment02.c
 *Assignment 2
 *Matthew Henderson
 *This program calculates average, standard deviation, and z-scores for a data set, this file contains the main function
 */

int main(int argc, char *argv[])
{
	printf("This program calculates the average, standard deviation, and z-scores of your data set.\n");
	float average;
	float deviation;

	//collects the size of the data set, it will repeat until a number greater that zero is given
	int size = 0;
	while (size <= 0)
	{

		printf("How large is the data set?\n");
		scanf("%d", &size);
	}

	float zScores[size];
	float data[size];
	int i;

	//collects the values of each data point
	for (i = 0; i < size; i++)
	{
		printf("What is the value of data #%d? ", i + 1);
		scanf("%f", &data[i]);
	}

	average = averager(data, size);
	printf("Average: %.5f\n", average);

	deviation = sDeviator(data, size);
	printf("Standard Deviation: %.5f\n", deviation);

	zScorer(data, size, zScores);
	printf("Z-Scores: %.5f", zScores[0]);

	for (i = 1; i < size; i++)
	{
		printf(", %.5f", zScores[i]);
	}

	printf("\n");

	return 0;
}
