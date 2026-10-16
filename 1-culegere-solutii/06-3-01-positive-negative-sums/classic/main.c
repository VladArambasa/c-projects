/* CULEGERE VI.3.1 - SUMS OF THE POSITIVE AND OF THE NEGATIVE VALUES
 * PRINT THE SUM OF THE POSITIVE VALUES AND THE SUM OF THE NEGATIVE VALUES OF N GIVEN NUMBERS
 * EXAMPLE: N=6, 6 9 -8 7 -5 -3 -> S POS=22  S NEG=-16 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i;
	int spos = 0, sneg = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) /* EVERY NUMBER GOES INTO ONE OF THE TWO SUMS (0 INTO NONE) */
	{
		if (a[i] > 0)
		{
			spos = spos + a[i];
		}
		else if (a[i] < 0)
		{
			sneg = sneg + a[i];
		}
	}

	printf("S pos=%d  S neg=%d\n", spos, sneg);

	return 0;
}
