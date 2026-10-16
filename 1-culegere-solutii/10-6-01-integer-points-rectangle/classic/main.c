/* CULEGERE X.6.1 - INTEGER POINTS IN A RECTANGLE
 * DREPTUNGHI.INT HOLDS THE ENDS OF A DIAGONAL OF A RECTANGLE WITH SIDES PARALLEL TO THE AXES
 * (REAL COORDINATES); WRITE IN PUNCTE.OUT HOW MANY POINTS WITH INTEGER COORDINATES ARE INSIDE
 * THE RECTANGLE OR ON ITS SIDES
 * EXAMPLE: -2.5 3 / 4 -1.75 -> 35 (X CAN BE -2 ... 4, Y CAN BE -1 ... 3: 7 * 5 = 35) */
#include <stdio.h> /* FOPEN, FSCANF, FPRINTF, FCLOSE, PRINTF */
#include <math.h>  /* CEIL, FLOOR */

/* HOW MANY INTEGERS LIE BETWEEN A AND B (A <= B), BOTH ENDS INCLUDED:
 * THE FIRST ONE IS CEIL(A), THE LAST ONE IS FLOOR(B) */
int integers_between(double a, double b)
{
	return (int)floor(b) - (int)ceil(a) + 1;
}

int main(void)
{
	FILE *in, *out;
	double xa = 0, ya = 0, xb = 0, yb = 0, t;
	int count;

	in = fopen("dreptunghi.int", "r");
	if (in == NULL)
	{
		printf("Cannot open dreptunghi.int\n");
		return 1;
	}
	fscanf(in, "%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
	fclose(in);

	/* ORDER THE ENDS SO THAT XA <= XB AND YA <= YB */
	if (xa > xb)
	{
		t = xa;
		xa = xb;
		xb = t;
	}
	if (ya > yb)
	{
		t = ya;
		ya = yb;
		yb = t;
	}

	/* EVERY GOOD X GOES WITH EVERY GOOD Y */
	count = integers_between(xa, xb) * integers_between(ya, yb);

	out = fopen("puncte.out", "w");
	fprintf(out, "%d\n", count);
	fclose(out);

	return 0;
}
