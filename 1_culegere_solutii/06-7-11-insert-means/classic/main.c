/* CULEGERE VI.7.11 - INSERT THE MEANS
 * BETWEEN EVERY TWO NEIGHBOURS OF A SEQUENCE OF N NUMBERS, INSERT THEIR ARITHMETIC MEAN
 * EXAMPLE: N=3, 2 4 5 -> 2 3 4 4.5 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	double a[MAX], b[2 * MAX]; /* B GETS N - 1 MORE ELEMENTS THAN A */
	int n = 0, m, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	m = 0; /* HOW MANY ELEMENTS B HAS */
	for (i = 0; i < n; i++)
	{
		b[m] = a[i]; /* FIRST THE ELEMENT ITSELF */
		m++;
		if (i < n - 1) /* THEN THE MEAN WITH ITS RIGHT NEIGHBOUR (THE LAST ONE HAS NONE) */
		{
			b[m] = (a[i] + a[i + 1]) / 2;
			m++;
		}
	}

	for (i = 0; i < m; i++)
	{
		printf("%g ", b[i]); /* %G WRITES 3 AND 4.5, NOT 3.000000 AND 4.500000 */
	}
	printf("\n");

	return 0;
}
