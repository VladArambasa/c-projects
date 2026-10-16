/* CULEGERE VI.3.11 - THE MINIMUM AND HOW OFTEN IT APPEARS (V1)
 * N NUMBERS ARE GIVEN; FIND THE SMALLEST VALUE AND PRINT HOW MANY TIMES IT APPEARS
 * EXAMPLE: N=8, 6 4 7 5 8 5 9 5 -> MIN=4 APPEARS 1 TIME
 * NOTE: THE BOOK'S EXAMPLE SAYS MIN=5 APPEARS 3 TIMES; THE CORRECT RESULT IS MIN=4 APPEARS 1 TIME
 * IDEA: FIRST FIND THE MINIMUM, THEN COUNT IT IN A SECOND PASS */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i, min;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	min = a[0]; /* FIRST PASS: THE SMALLEST VALUE */
	for (i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	for (i = 0; i < n; i++) /* SECOND PASS: HOW MANY TIMES IT APPEARS */
	{
		if (a[i] == min)
		{
			count++;
		}
	}

	printf("min=%d appears %d %s\n", min, count, (count == 1) ? "time" : "times");

	return 0;
}
