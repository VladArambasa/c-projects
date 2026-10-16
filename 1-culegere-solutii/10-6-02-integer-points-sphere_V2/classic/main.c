/* CULEGERE X.6.2 - INTEGER POINTS IN A SPHERE
 * HOW MANY POINTS WITH INTEGER COORDINATES ARE IN THE SPHERE OF RADIUS R (NATURAL, R <= 30)
 * CENTERED IN THE ORIGIN? THE DISTANCE FROM (X, Y, Z) TO THE ORIGIN IS SQRT(X*X + Y*Y + Z*Z)
 * EXAMPLE: R = 4 -> 257 (THE POINTS ON THE SURFACE ARE COUNTED TOO)
 * IMPROVEMENT: FOR EACH X, Y THE Z FROM -ZMAX TO ZMAX ARE COUNTED AT ONCE: R*R STEPS, NOT R*R*R */
#include <stdio.h> /* PRINTF, SCANF */
#include <math.h>  /* SQRT */

int main(void)
{
	int r = 0, x, y, rest, zmax, count = 0;

	printf("R = ");
	scanf("%d", &r);

	for (x = -r; x <= r; x++)
	{
		for (y = -r; y <= r; y++)
		{
			/* Z*Z CAN BE AT MOST WHAT IS LEFT OF R*R */
			rest = r * r - x * x - y * y;
			if (rest >= 0)
			{
				/* THE LARGEST ZMAX WITH ZMAX*ZMAX <= REST (SQRT IS EXACT
				 * FOR A PERFECT SQUARE, AND THE NUMBERS ARE SMALL) */
				zmax = (int)sqrt(rest);
				count = count + 2 * zmax + 1; /* Z = -ZMAX, ..., 0, ..., ZMAX */
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
