/* CULEGERE X.6.8 - AREA OF A CONVEX POLYGON
 * THE VERTICES A(1), A(2), ..., A(N) OF A CONVEX POLYGON (3 <= N <= 100, NATURAL COORDINATES < 50)
 * ARE READ IN ORDER; PRINT ITS AREA, CUTTING IT INTO THE TRIANGLES A(1) A(I) A(I+1)
 * EXAMPLE: (0 0) (4 0) (4 3) (0 3) -> 12.0 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

/* TWICE THE AREA OF THE TRIANGLE (XA, YA) (XB, YB) (XC, YC), FROM ITS COORDINATES:
 * |(XB - XA) * (YC - YA) - (XC - XA) * (YB - YA)|, ALWAYS A WHOLE NUMBER */
int twice_area(int xa, int ya, int xb, int yb, int xc, int yc)
{
	return abs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}

int main(void)
{
	int x[MAX + 1] = {0}, y[MAX + 1] = {0};
	int n = 0, i, sum = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d vertices in order (x y): ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	/* THE DIAGONALS FROM A(1) CUT THE CONVEX POLYGON INTO THE TRIANGLES A(1) A(I) A(I+1) */
	for (i = 2; i < n; i++)
	{
		sum = sum + twice_area(x[1], y[1], x[i], y[i], x[i + 1], y[i + 1]);
	}

	printf("Area = %.1f\n", sum / 2.0); /* HALF OF A WHOLE NUMBER: ONE DECIMAL IS ENOUGH */

	return 0;
}
