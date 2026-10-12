/* CULEGERE XIII.2.9 - INSERTING MEANS
 * A VECTOR OF N NATURAL NUMBERS SMALLER THAN 101 AND A NATURAL NUMBER A ARE GIVEN. BETWEEN TWO
 * NEIGHBOURS WHOSE ABSOLUTE DIFFERENCE IS AT LEAST A, THEIR ARITHMETIC MEAN IS INSERTED, UNTIL
 * EVERY TWO NEIGHBOURS DIFFER BY LESS THAN A. PRINT THE FINAL VECTOR
 * EXAMPLE: 1 10 4 AND A=3 -> 1 3.25 5.5 7.75 10 8.5 7 5.5 4
 * ASSUMPTION: AT MOST 100 NUMBERS AND A >= 1 (WITH A = 0 THE INSERTIONS WOULD NEVER STOP) */
#include <stdio.h> /* PRINTF, SCANF */
#include <math.h>  /* FABS */

/* EACH OF THE 99 GAPS (AT MOST 100) IS CUT INTO AT MOST 128 PARTS (100 / 128 < 1), SO THE
 * VECTOR NEVER HAS MORE THAN 99 * 128 + 1 = 12673 NUMBERS */
#define MAX 12673

/* PUTS X ON POSITION POS, MOVING THE ELEMENTS FROM POS ON ONE PLACE TO THE RIGHT;
 * RETURNS THE NEW LENGTH */
int insert(double v[], int len, int pos, double x)
{
	int i;

	for (i = len; i > pos; i--)
	{
		v[i] = v[i - 1];
	}
	v[pos] = x;
	return len + 1;
}

int main(void)
{
	double v[MAX] = {0};
	int n = 0, a = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &v[i]);
	}
	printf("a = ");
	scanf("%d", &a);

	/* WHEN TWO NEIGHBOURS ARE TOO FAR APART, PUT THEIR MEAN BETWEEN THEM AND CHECK THE SAME
	 * PLACE AGAIN; MOVE ON ONLY WHEN THE PAIR IS CLOSE ENOUGH */
	i = 0;
	while (i < n - 1)
	{
		if (fabs(v[i] - v[i + 1]) >= a)
		{
			n = insert(v, n, i + 1, (v[i] + v[i + 1]) / 2);
		}
		else
		{
			i++;
		}
	}

	printf("The new vector: ");
	for (i = 0; i < n; i++)
	{
		printf("%g ", v[i]);
	}
	printf("\n");

	return 0;
}
