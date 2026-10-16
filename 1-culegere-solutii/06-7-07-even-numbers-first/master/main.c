/* CULEGERE VI.7.7 - EVEN NUMBERS FIRST
 * N INTEGERS ARE READ; USING ANOTHER VECTOR, PUT THE EVEN NUMBERS AT THE BEGINNING, THEN THE ODD
 * ONES (EACH GROUP KEEPS THE ORDER IN WHICH IT WAS READ, AS IN THE EXAMPLE)
 * EXAMPLE: N=4, 3 4 6 5 -> 4 6 3 5 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, m, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	m = 0; /* HOW MANY ELEMENTS ARE ALREADY IN B */
	for (i = 0; i < n; i++) /* FIRST PASS: COPY THE EVEN NUMBERS */
	{
		if (a[i] % 2 == 0)
		{
			b[m] = a[i];
			m++;
		}
	}
	for (i = 0; i < n; i++) /* SECOND PASS: COPY THE ODD NUMBERS AFTER THEM */
	{
		if (a[i] % 2 != 0) /* != 0, NOT == 1: FOR A NEGATIVE ODD NUMBER THE REMAINDER IS -1 */
		{
			b[m] = a[i];
			m++;
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}
