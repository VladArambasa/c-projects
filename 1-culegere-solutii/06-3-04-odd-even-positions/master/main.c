/* CULEGERE VI.3.4 - SUMS ON ODD AND ON EVEN POSITIONS
 * IN A SEQUENCE OF N INTEGERS PRINT THE SUM OF THE ELEMENTS ON ODD POSITIONS AND THE SUM OF THE
 * ELEMENTS ON EVEN POSITIONS (THE POSITIONS ARE COUNTED FROM 1)
 * EXAMPLE: N=6, 3 1 5 4 6 7 -> S_ODD=14  S_EVEN=12 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i;
	int s_odd = 0, s_even = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 1) /* A[I] IS ON POSITION I + 1 */
		{
			s_odd = s_odd + a[i];
		}
		else
		{
			s_even = s_even + a[i];
		}
	}

	printf("s_odd=%d  s_even=%d\n", s_odd, s_even);

	return 0;
}
