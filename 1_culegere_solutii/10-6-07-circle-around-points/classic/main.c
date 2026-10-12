/* CULEGERE X.6.7 - CIRCLE AROUND THE POINTS
 * N POINTS ARE GIVEN BY THEIR COORDINATES (NATURAL NUMBERS <= 50); FIND THE CENTER AND THE RADIUS
 * OF A CIRCLE THAT HOLDS ALL THE POINTS (INSIDE OR ON THE CIRCLE) AND HAS ITS CENTER IN ONE OF
 * THE GIVEN POINTS
 * EXAMPLE: (0 0) (4 0) (0 3) (2 1) -> CENTER (2, 1), RADIUS 2.83
 * ASSUMPTION: THE SMALLEST SUCH CIRCLE IS WANTED (A LARGER ONE WOULD ALWAYS WORK); IF SEVERAL
 * CENTERS NEED THE SAME RADIUS, THE FIRST ONE IS PRINTED; AT MOST 100 POINTS */
#include <stdio.h> /* PRINTF, SCANF */
#include <math.h>  /* SQRT */

#define MAX 100

int main(void)
{
	int x[MAX] = {0}, y[MAX] = {0};
	int n = 0, i, j, d, farthest, best = 0, best_far = -1;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d points (x y): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	/* WITH THE CENTER IN POINT I, THE RADIUS MUST REACH THE FARTHEST POINT;
	 * SQUARED DISTANCES ARE COMPARED, SO EVERYTHING STAYS IN INTEGERS */
	for (i = 0; i < n; i++)
	{
		farthest = 0;
		for (j = 0; j < n; j++)
		{
			d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if (d > farthest)
			{
				farthest = d;
			}
		}
		/* KEEP THE CENTER THAT NEEDS THE SMALLEST RADIUS */
		if (best_far == -1 || farthest < best_far)
		{
			best_far = farthest;
			best = i;
		}
	}

	printf("Center: (%d, %d)\n", x[best], y[best]);
	printf("Radius: %.2f\n", sqrt(best_far)); /* ONLY NOW THE REAL DISTANCE IS NEEDED */

	return 0;
}
