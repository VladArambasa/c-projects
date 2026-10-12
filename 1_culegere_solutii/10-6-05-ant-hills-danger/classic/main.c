/* CULEGERE X.6.5 - ANT HILLS IN DANGER
 * FURNICI.IN: M ANT HILLS (POINTS), THEN A POLYGON OF N VERTICES (CONVEX OR CONCAVE), ALL WITH
 * POSITIVE INTEGER COORDINATES (3 < N < 50, 1 < M < 100); FOR EACH ANT HILL, IN THE INPUT ORDER,
 * WRITE IN FURNICI.OUT "IN DANGER!" IF IT IS INSIDE THE POLYGON OR ON ONE OF ITS SIDES, OTHERWISE
 * WRITE "SAFE!"
 * EXAMPLE: THE FILE OF THE BOOK -> SAFE! / IN DANGER! / SAFE! / SAFE! / IN DANGER!
 * ASSUMPTION: THE DANGER MESSAGE ALWAYS ENDS WITH '!' (THE BOOK WRITES IT BOTH WITH AND WITHOUT) */
#include <stdio.h> /* FOPEN, FSCANF, FPRINTF, FCLOSE, PRINTF */

#define MAXM 100
#define MAXN 50

int vx[MAXN], vy[MAXN]; /* THE VERTICES OF THE POLYGON */
int n = 0;              /* HOW MANY VERTICES */

/* 1 IF POINT (X, Y) IS ON THE SIDE THAT JOINS VERTEX I AND VERTEX J */
int on_side(int x, int y, int i, int j)
{
	/* THE CROSS PRODUCT IS 0 ONLY WHEN THE POINT IS ON THE LINE OF THE SIDE */
	if ((vx[j] - vx[i]) * (y - vy[i]) - (vy[j] - vy[i]) * (x - vx[i]) != 0)
	{
		return 0;
	}
	/* ON THE LINE, IT MUST ALSO BE BETWEEN THE TWO VERTICES: X - VX[I] AND X - VX[J]
	 * DO NOT HAVE THE SAME SIGN (THEIR PRODUCT IS <= 0), AND THE SAME FOR Y */
	if ((x - vx[i]) * (x - vx[j]) <= 0 && (y - vy[i]) * (y - vy[j]) <= 0)
	{
		return 1;
	}
	return 0;
}

/* 1 IF POINT (X, Y) IS INSIDE THE POLYGON OR ON ONE OF ITS SIDES */
int in_danger(int x, int y)
{
	int i, j, cross, inside = 0;

	for (i = 0; i < n; i++)
	{
		j = (i + 1) % n; /* SIDE FROM VERTEX I TO THE NEXT ONE; THE LAST GOES TO 0 */
		if (on_side(x, y, i, j))
		{
			return 1;
		}
	}

	/* A RAY GOES FROM THE POINT TO THE RIGHT; THE POINT IS INSIDE THE POLYGON
	 * WHEN THE RAY CROSSES THE SIDES AN ODD NUMBER OF TIMES */
	for (i = 0; i < n; i++)
	{
		j = (i + 1) % n;
		/* THE SIDE CROSSES THE LINE OF THE RAY: ONE END IS ABOVE IT, THE OTHER IS NOT */
		if ((vy[i] > y) != (vy[j] > y))
		{
			/* THE CROSSING IS ON THE RIGHT OF THE POINT WHEN THE POINT IS ON THE
			 * LEFT OF THE SIDE WALKED UPWARDS; THE CROSS PRODUCT SIGN TELLS THAT */
			cross = (vx[j] - vx[i]) * (y - vy[i]) - (vy[j] - vy[i]) * (x - vx[i]);
			if ((vy[j] > vy[i] && cross > 0) || (vy[j] < vy[i] && cross < 0))
			{
				inside = 1 - inside;
			}
		}
	}
	return inside;
}

int main(void)
{
	FILE *in, *out;
	int hx[MAXM] = {0}, hy[MAXM] = {0}; /* THE ANT HILLS */
	int m = 0, i;

	in = fopen("furnici.in", "r");
	if (in == NULL)
	{
		printf("Cannot open furnici.in\n");
		return 1;
	}
	fscanf(in, "%d", &m);
	for (i = 0; i < m; i++)
	{
		fscanf(in, "%d %d", &hx[i], &hy[i]);
	}
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d %d", &vx[i], &vy[i]);
	}
	fclose(in);

	out = fopen("furnici.out", "w");
	for (i = 0; i < m; i++)
	{
		if (in_danger(hx[i], hy[i]))
		{
			fprintf(out, "in danger!\n");
		}
		else
		{
			fprintf(out, "safe!\n");
		}
	}
	fclose(out);

	return 0;
}
