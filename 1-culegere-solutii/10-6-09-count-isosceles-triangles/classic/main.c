/* CULEGERE X.6.9 - COUNT ISOSCELES TRIANGLES
 * N POINTS (N >= 3, INTEGER COORDINATES IN [0, 500]) ARE READ; PRINT HOW MANY ISOSCELES
 * TRIANGLES CAN BE FORMED BY JOINING THREE OF THE POINTS
 * EXAMPLE: (0 0) (2 0) (2 2) (0 2) (1 1) -> 8: THE 4 TRIANGLES OF THREE CORNERS OF THE SQUARE AND
 * THE 4 OF THE CENTER WITH TWO NEIGHBOR CORNERS (THE CENTER WITH TWO OPPOSITE CORNERS IS A LINE)
 * ASSUMPTION: THE POINTS ARE DIFFERENT; AT MOST 100 POINTS */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int x[MAX], y[MAX];

/* SQUARE OF THE DISTANCE BETWEEN POINTS I AND J; EQUAL SQUARES MEAN EQUAL SIDES, SO NO SQRT */
int dist2(int i, int j)
{
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

/* CROSS PRODUCT OF THE VECTORS I->J AND I->K: IT IS 0 WHEN THE THREE POINTS ARE ON ONE LINE */
int cross(int i, int j, int k)
{
	return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}

int main(void)
{
	int n = 0, i, j, k, a, b, c, count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d points (x y): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	/* EVERY GROUP OF THREE POINTS, TAKEN ONCE (I < J < K) */
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				/* THREE POINTS ON ONE LINE DO NOT FORM A TRIANGLE */
				if (cross(i, j, k) != 0)
				{
					a = dist2(i, j);
					b = dist2(j, k);
					c = dist2(i, k);
					if (a == b || b == c || a == c) /* TWO EQUAL SIDES */
					{
						count++;
					}
				}
			}
		}
	}

	printf("Isosceles triangles: %d\n", count);

	return 0;
}
