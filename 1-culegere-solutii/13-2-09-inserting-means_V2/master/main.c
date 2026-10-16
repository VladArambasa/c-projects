/* CULEGERE XIII.2.9 - INSERTING MEANS
 * A VECTOR OF N NATURAL NUMBERS SMALLER THAN 101 AND A NATURAL NUMBER A ARE GIVEN. BETWEEN TWO
 * NEIGHBOURS WHOSE ABSOLUTE DIFFERENCE IS AT LEAST A, THEIR ARITHMETIC MEAN IS INSERTED, UNTIL
 * EVERY TWO NEIGHBOURS DIFFER BY LESS THAN A. PRINT THE FINAL VECTOR
 * EXAMPLE: 1 10 4 AND A=3 -> 1 3.25 5.5 7.75 10 8.5 7 5.5 4
 * ASSUMPTION: AT MOST 100 NUMBERS AND A >= 1 (WITH A = 0 THE INSERTIONS WOULD NEVER STOP)
 * V2: NO INSERTIONS AND NO BIG ARRAY; EACH GAP IS CUT AT ONCE INTO 2, 4, 8... EQUAL PARTS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	double v[MAX] = {0};
	double step;
	int n = 0, a = 0, i, j, parts;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &v[i]);
	}
	printf("a = ");
	scanf("%d", &a);

	/* A MEAN CUTS A GAP INTO TWO EQUAL HALVES, AND BOTH HALVES ARE LATER CUT THE SAME WAY,
	 * SO EVERY GAP ENDS UP CUT INTO 2, 4, 8... EQUAL PARTS, EACH ONE SMALLER THAN A */
	printf("The new vector: ");
	for (i = 0; i < n; i++)
	{
		printf("%g ", v[i]);
		if (i < n - 1)
		{
			step = v[i + 1] - v[i];
			parts = 1;
			while (fabs(step) >= a)
			{
				step = step / 2; /* ONE MORE ROUND OF MEANS HALVES EVERY PART */
				parts = parts * 2;
			}
			for (j = 1; j < parts; j++)
			{
				printf("%g ", v[i] + j * step); /* THE MEANS THAT GO INTO THIS GAP */
			}
		}
	}
	printf("\n");

	return 0;
}
