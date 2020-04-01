#include <stdio.h>
#include <math.h>

//Struct that contains x and y. Should be an array so that multiple dimensions could be used.
typedef struct coords_struct
{
	double x;
	double y;

} coords;

//Creates a coordinate array
void makeCoordinate(int n, coords *coordArry)
{
	int i;
	double tempValue;

	for (i = 0; i < n; i++)
	{

		printf("What is the x coordinate of point %d?\n", i + 1);
		scanf("%lf", &tempValue);
		coordArry[i].x = tempValue;

		printf("What is the x coordinate of point %d?\n", i + 1);
		scanf("%lf", &tempValue);
		coordArry[i].y = tempValue;
	}
	printf("\nCoordinate %d is (%lf,%lf)\n", 1, coordArry[0].x, coordArry[0].y);
	printf("Coordinate %d is (%lf,%lf)\n\n", 2, coordArry[1].x, coordArry[1].y);
}

//Calculates the distance in an array of coordinates
void calcDistance(int n, coords *coordArry)
{

	double distance = 0.0;
	double x = pow(coordArry[0].x - coordArry[1].x, 2);
	double y = pow(coordArry[0].y - coordArry[1].y, 2);

	distance = sqrt(x + y);
	printf("The distance from point #1 to point #2 is:\n %lf\n", distance);
}

//Calculates the midpoint for an array of coordinates
void calcMidPoint(int n, coords *coordArry)
{

	coords middle;
	middle.x = (coordArry[0].x + coordArry[1].x) / 2;
	middle.y = (coordArry[0].y + coordArry[1].y) / 2;
	printf("The midpoint is located at: \n (%lf,%lf)\n\n", middle.x, middle.y);
}
