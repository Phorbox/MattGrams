#include <stdio.h>
#include <math.h>

// Author: Matthew Henderson    
// Assignment Number: HW 01
// File Name: HW01_Henderson.zip
// Course/Section: CS 2123 Section 0D1
// Date: 09/04/20
// Instructor: Bernard Ku

int main(void)
{
    int x, y;
    float val;
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);
    printf("pow(%d, %d) = %f\n", x, y, pow(x, y));
    printf("Enter value: ");
    scanf("%f", &val);
    printf("sqrt(%f) = %f\n", val, sqrt(val));
    return 0;
}