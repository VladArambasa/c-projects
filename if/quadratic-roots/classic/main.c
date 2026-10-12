/* ROOTS OF A QUADRATIC EQUATION A*X*X + B*X + C = 0 */
#include <stdio.h> /* PRINTF, SCANF */
#include <math.h>  /* SQRT */

int main(void)
{
	double a = 0, b = 0, c = 0, delta, x1, x2;

	printf("Enter a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a == 0)
	{
		printf("Not a quadratic equation (a is 0)\n");
		return 1;
	}

	delta = b * b - 4 * a * c; /* THE DISCRIMINANT DECIDES THE KIND OF ROOTS */

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		printf("Two real roots: %g and %g\n", x1 + 0.0, x2 + 0.0); /* + 0.0 TURNS -0 INTO 0 */
	}
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		printf("One double root: %g\n", x1 + 0.0);
	}
	else
	{
		printf("No real roots (the roots are complex)\n");
	}

	return 0;
}
