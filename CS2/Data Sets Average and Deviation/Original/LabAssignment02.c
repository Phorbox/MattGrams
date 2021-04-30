#include <stdio.h>
#include <math.h>



/*LabAssignment02.c
 *Assignment 2
 *Matthew Henderson
 *This program calculates average, standard deviation, and z-scores for a data set, this file contains the main function
 */

/*This function averages the values of an array.
 *Parameter:
 *data[]: array to be averaged
 *size: size of the array
 *
 *Return:
 *answer: a float of the average of the parameters
 */
double averager(float data[],int size)
{
	int i;
	float answer = 0.0;

	for(i = 0; i < size; i++)
	{
		answer += data[i];
	}

	answer /= size;

	return answer;
}

/*This function finds the standard deviation of values of an array, numebr of values.
 *Parameter:
 *data[]: array to be standard deviated
 *size: size of the array
 *
 *Return:
 *answer: a float of the deviation of the parameters
 */
double sDeviator(float data[], int size)
{

	int i;
	float answer = 0.0;
	float average;
	average =  averager(data,size);

	for(i = 0; i < size; i++)
	{
		answer += ((data[i]-average)*(data[i]-average));
		
	}

	answer /= size;
	answer = sqrt(answer);
	

	return answer;


}


/*This function averages the values of an array.
 *Parameter:
 *data[]: array to be averaged
 *size: size of the array
 *zScores[]: the array that gets edited with the function with the zScores  
 *
 *Return:
 *Void
 */
void zScorer(float data[], int size, float zScores[])
{
	int i;
	float average;
	float deviation;
	float answers = 0.0;

	deviation = sDeviator(data, size);
	average = averager(data, size);	

	for(i = 0; i < size; i++)
	{	
		answers = (data[i] - average) / deviation;
		zScores[i] = answers;


	}
}

int main(int argc, char* argv[])
{
	printf("This program calculates the average, standard deviation, and z-scores of your data set.\n");
	float average;
	float deviation;
	
	//collects the size of the data set, it will repeat until a number greater that zero is given 
	int size = 0;
	while( size <= 0){

		printf("How large is the data set?\n");
		scanf ("%d", &size);
	}

	float zScores[size];	
	float data[size]; 
	int i;

	//collects the values of each data point
	for(i = 0; i < size; i++)
	{
		printf("What is the value of data #%d? ", i+1);
		scanf("%f", &data[i]);
	} 

	average = averager(data,size);
	printf("Average: %.5f\n", average);

	deviation = sDeviator(data,size);
	printf("Standard Deviation: %.5f\n", deviation);

	zScorer(data, size, zScores);
	printf("Z-Scores: %.5f",zScores[0]);
	

	for(i = 1; i < size; i++)
	{
		printf(", %.5f", zScores[i]);
	} 
	
	printf("\n");


	return 0;
}
