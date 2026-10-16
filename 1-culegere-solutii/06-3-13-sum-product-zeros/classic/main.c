/* CULEGERE VI.3.13 - SUM, PRODUCT AND ZEROS
 * FOR A VECTOR OF N REAL NUMBERS PRINT THE SUM OF THE POSITIVE COMPONENTS, THE PRODUCT OF THE
 * NEGATIVE ONES AND THE NUMBER OF ZERO COMPONENTS
 * EXAMPLE: N=7, 1 0 -4 -3 0 5 -1 -> S=6 P=-12 C=2
 * ASSUMPTION: WITHOUT NEGATIVE COMPONENTS THE PRODUCT KEEPS ITS START VALUE, 1 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	double a[MAX] = {0};
	double s = 0, p = 1; /* A SUM STARTS FROM 0, A PRODUCT FROM 1 */
	int n = 0, i, c = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			s = s + a[i];
		}
		else if (a[i] < 0)
		{
			p = p * a[i];
		}
		else
		{
			c++; /* NEITHER POSITIVE NOR NEGATIVE: A ZERO */
		}
	}

	printf("s=%g p=%g c=%d\n", s, p, c); /* %G WRITES 6 AND NOT 6.000000 */

	return 0;
}
