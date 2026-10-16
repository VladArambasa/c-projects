/* CULEGERE X.6.12 - POINTS INSIDE, ON AND OUTSIDE A RECTANGLE
 * A RECTANGLE (SIDES PARALLEL TO THE AXES) IS GIVEN BY ITS TOP-LEFT AND BOTTOM-RIGHT CORNERS,
 * THEN N POINTS (NATURAL COORDINATES < 500); PRINT HOW MANY POINTS ARE INSIDE THE RECTANGLE,
 * ON IT AND OUTSIDE IT
 * EXAMPLE: CORNERS (1 5) (6 1), POINTS (3 3) (1 2) (6 5) (7 3) (0 0) -> INSIDE 1, ON 2,
 * OUTSIDE 2 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int xa = 0, ya = 0, xb = 0, yb = 0, left, right, bottom, top;
	int n = 0, i, x = 0, y = 0, inside = 0, on = 0, outside = 0;

	printf("Top-left corner (x y): ");
	scanf("%d %d", &xa, &ya);
	printf("Bottom-right corner (x y): ");
	scanf("%d %d", &xb, &yb);

	/* THE SIDES OF THE RECTANGLE; TAKING THE SMALLER AND THE LARGER VALUE MAKES IT
	 * WORK WHETHER THE Y AXIS GOES UP OR DOWN */
	left = xa;
	right = xb;
	if (xa > xb)
	{
		left = xb;
		right = xa;
	}
	bottom = ya;
	top = yb;
	if (ya > yb)
	{
		bottom = yb;
		top = ya;
	}

	printf("n = ");
	scanf("%d", &n);
	printf("The %d points (x y): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		if (x < left || x > right || y < bottom || y > top)
		{
			outside++; /* BEYOND ONE OF THE SIDES */
		}
		else if (x == left || x == right || y == bottom || y == top)
		{
			on++; /* NOT OUTSIDE, BUT ON ONE OF THE SIDES */
		}
		else
		{
			inside++;
		}
	}

	printf("Inside: %d\n", inside);
	printf("On the rectangle: %d\n", on);
	printf("Outside: %d\n", outside);

	return 0;
}
