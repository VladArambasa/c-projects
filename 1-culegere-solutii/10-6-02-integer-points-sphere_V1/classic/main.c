/* CULEGERE X.6.2 - INTEGER POINTS IN A SPHERE
 * HOW MANY POINTS WITH INTEGER COORDINATES ARE IN THE SPHERE OF RADIUS R (NATURAL, R <= 30)
 * CENTERED IN THE ORIGIN? THE DISTANCE FROM (X, Y, Z) TO THE ORIGIN IS SQRT(X*X + Y*Y + Z*Z)
 * EXAMPLE: R = 4 -> 257 (THE POINTS ON THE SURFACE ARE COUNTED TOO) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int r = 0, x, y, z, count = 0;

	printf("R = ");
	scanf("%d", &r);

	/* TRY EVERY INTEGER POINT OF THE CUBE -R ... R THAT HOLDS THE SPHERE;
	 * DISTANCE <= R IS TESTED AS X*X + Y*Y + Z*Z <= R*R, SO NO SQRT IS NEEDED */
	for (x = -r; x <= r; x++)
	{
		for (y = -r; y <= r; y++)
		{
			for (z = -r; z <= r; z++)
			{
				if (x * x + y * y + z * z <= r * r)
				{
					count++;
				}
			}
		}
	}

	printf("%d\n", count);

	return 0;
}
