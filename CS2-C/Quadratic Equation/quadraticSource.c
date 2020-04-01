#include <stdio.h>
#include <math.h>

/*
 *	quadraticFormula.C
 *	Assignment 1
 *	Matthew Henderson
 *	This program solves for the X intercepts of
 *	a polynomial such as Ax^2 + Bx + C.
 */

int main(int argc, char *argv[])
{
	float coeff[3];
	char label = 'A';
	float solutions[2];
	int i;

	/*The quadratic formula is

	x = -b +- sqrt(B^2 - 4*A*C) / 2 * A
	*/

	printf("\nThis program uses the quadratic formula to solve for the x-intercepts of trinomials. \nYou will need to input the values of the coefficients.\n\n");

	//User input for the coefficients for the polynomial
	for (i = 0; i < 3; i++)
	{

		printf("What is the value of %c?\n", label);
		label++;
		scanf("%f", &coeff[i]);
	}

	//Checks immediately for an invalid polynomial
	if (coeff[0] == 0)
	{

		printf("Invalid trinomial. The denominator is zero.\n\n");
		return 0;
	}

	//Math for the radicand
	solutions[0] = pow(coeff[1], 2);
	solutions[0] = solutions[0] - (4.0 * coeff[0] * coeff[2]);

	//Checks for invalid radicand
	if (solutions[0] < 0)
	{

		printf("Invalid trinomial. The radicand is negative, so the solutions will be imaginary.\n\n");
		return 0;
	}

	//continues the equation the equation
	solutions[0] = sqrt(solutions[0]);

	// creates the second answer to the question
	solutions[1] = -solutions[0];

	//Final math for solutions
	for (i = 0; i < 2; i++)
	{
		solutions[i] = (-coeff[1] + solutions[i]) / (2.0 * coeff[0]);
	}

	printf("\nX intercepts are: %f and %f.\n\n", solutions[0], solutions[1]);

	return 0;
}
