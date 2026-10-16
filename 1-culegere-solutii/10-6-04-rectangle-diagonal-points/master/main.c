/* CULEGERE X.6.4 - POINTS IN A RECTANGLE AND ON ITS DIAGONALS
 * PUNCTE.IN: N (0 < N < 100), THE N POINTS, THEN THE TOP-LEFT AND THE BOTTOM-RIGHT CORNERS OF A
 * RECTANGLE WITH SIDES PARALLEL TO THE AXES (NATURAL COORDINATES < 3000); WRITE IN PUNCTE.OUT THE
 * NUMBER OF POINTS INSIDE THE RECTANGLE AND THE NUMBER OF POINTS ON ITS TWO DIAGONALS
 * EXAMPLE: (3 4) (2 4) (5 6) (5 1) (4 2) (0 6) (2 2) (3 2), CORNERS (1 5) (5 1) -> 5 4
 * ASSUMPTION: INSIDE MEANS STRICTLY INSIDE: THE CORNER (5 1) IS NOT ONE OF THE 5 OF THE EXAMPLE
 * ASSUMPTION: A DIAGONAL IS THE SEGMENT JOINING TWO OPPOSITE CORNERS, ENDS INCLUDED: THE 4 OF THE
 * EXAMPLE ARE (2 4) (5 1) (4 2) (2 2); (0 6) IS ON THE LINE OF A DIAGONAL, BUT NOT ON THE SEGMENT
 * ASSUMPTION: A POINT ON BOTH DIAGONALS (THE CENTER) IS COUNTED ONCE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	FILE *in, *out;
	int x[MAX] = {0}, y[MAX] = {0};
	int n = 0, i, xa = 0, ya = 0, xb = 0, yb = 0;
	int left, right, bottom, top, width, height, inside = 0, diagonal = 0;

	in = fopen("puncte.in", "r");
	if (in == NULL)
	{
		printf("Cannot open puncte.in\n");
		return 1;
	}
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d %d", &x[i], &y[i]);
	}
	fscanf(in, "%d %d %d %d", &xa, &ya, &xb, &yb); /* THE CORNERS COME AFTER THE POINTS */
	fclose(in);

	/* THE SIDES OF THE RECTANGLE: THE SMALLER AND THE LARGER X, THE SMALLER AND THE LARGER Y */
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
	width = right - left;
	height = top - bottom;

	for (i = 0; i < n; i++)
	{
		/* INSIDE: STRICTLY BETWEEN LEFT AND RIGHT AND STRICTLY BETWEEN BOTTOM AND TOP */
		if (x[i] > left && x[i] < right && y[i] > bottom && y[i] < top)
		{
			inside++;
		}
		/* A POINT OF A DIAGONAL IS IN THE RECTANGLE (SIDES INCLUDED) AND ON THE LINE OF
		 * THE DIAGONAL: (X - LEFT) / WIDTH = (Y - BOTTOM) / HEIGHT FOR THE ONE GOING UP,
		 * (X - LEFT) / WIDTH = (TOP - Y) / HEIGHT FOR THE OTHER ONE; NO DIVISION IS DONE */
		if (x[i] >= left && x[i] <= right && y[i] >= bottom && y[i] <= top)
		{
			if ((x[i] - left) * height == (y[i] - bottom) * width ||
			    (x[i] - left) * height == (top - y[i]) * width)
			{
				diagonal++;
			}
		}
	}

	out = fopen("puncte.out", "w");
	fprintf(out, "%d %d\n", inside, diagonal);
	fclose(out);

	return 0;
}
