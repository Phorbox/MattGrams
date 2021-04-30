#include <stdio.h>
#include <stdlib.h>
#include "point.h"

/*
 *	calcSource.C
 *	Assignment 4
 *	Matthew Henderson
 *	This program finds the midpoint and distance 
 *	of two points
 */

int main(int argc, char *argv[])
{
    int n = 2;
    coords *cPtr;
    cPtr = (coords *)malloc(n * sizeof(coords));
    makeCoordinate(n, cPtr);
    calcDistance(n, cPtr);
    calcMidPoint(n, cPtr);

    return 0;
}
