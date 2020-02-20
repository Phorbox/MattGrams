#include <stdio.h>

typedef struct coords_struct
{
	double x;
	double y;

} coords;

void makeCoordinate(int n, coords* coordArry)
{
	int i;
	int j;
	double tempValue;
	
	// int j 
	// for(j = 0; j<n; j++)
	// {
	// 		for(i = 0; i < (sizeof(coords)/sizeof(coords.x)); i++)
	// 	{
	// 		printf("What is the %c coordinate of point %d?\n" , 88+i , i+1);	
	// 		scanf(%lf, &tempValue);
	// //		scanf(%lf, &coordArry + (n * sizeof(coords)) + (i * sizeof(coords.x));
	// 		coordArry[i]->/*  Dynamic reference to struct component  */ = tempValue 
	// 	}
	// }
	

		for(i = 0; i < n; i++)
		{
			
			printf("What is the x coordinate of point %d?\n" , i+1);	
			scanf(%lf, &tempValue);
			coordArry[n]->x = tempValue;
			
			printf("What is the y coordinate of point %d?\n" , i+1);	
			scanf(%lf, &tempValue);
			coordArry[n]->y = tempValue;
			 
		}
	


}

void calcDistance(int n , coords* coordArry)
{
	double distance = 0.0;
	double x = pow( coordArry[0]->x - coordArry[1]->x, 2 );
	double y = pow( coordArry[0]->y - coordArry[1]->y, 2 );

	distance =  sqrt( x + y );
	printf("The distance from point #1 to point #2 is:\n %lf",distance); 
}



void calcMidPoint(int n , coords* coordArry)
{

	coords middle;
	middle.x = ( coordArry[0]->x - coordArry[1]->x ) / 2;
	middle.y = ( coordArry[0]->y - coordArry[1]->y ) / 2;
	print("The midpoint is located at: \n (%d,%d)",middle.x,middle.y);
}
