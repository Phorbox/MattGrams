#ifndef   POINT_H
#define   POINT_H

typedef struct coords_struct
{
	double x;
	double y;

} coords;

void makeCoordinate(int n, coords* coordArry);
void calcDistance(int n , coords* coordArry);
void calcMidPoint(int n , coords* coordArry);


#endif