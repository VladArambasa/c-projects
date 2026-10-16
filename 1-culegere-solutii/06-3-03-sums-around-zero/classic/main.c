/* CULEGERE VI.3.3 - SUMS BEFORE AND AFTER THE ZERO
 * OF N INTEGERS EXACTLY ONE IS 0, AND IT IS NEITHER THE FIRST NOR THE LAST. PRINT THE SUM OF THE
 * NUMBERS BEFORE THIS 0 AND THE SUM OF THE NUMBERS AFTER IT
 * EXAMPLE: N=5, 4 5 1 0 7 -> S1=10  S2=7 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i, p;
	int s1 = 0, s2 = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	p = 0;
	while (p < n && a[p] != 0) /* FIND THE POSITION OF THE ZERO */
	{
		p++;
	}

	for (i = 0; i < p; i++) /* THE NUMBERS BEFORE THE ZERO */
	{
		s1 = s1 + a[i];
	}
	for (i = p + 1; i < n; i++) /* THE NUMBERS AFTER THE ZERO */
	{
		s2 = s2 + a[i];
	}

	printf("s1=%d  s2=%d\n", s1, s2);

	return 0;
}
