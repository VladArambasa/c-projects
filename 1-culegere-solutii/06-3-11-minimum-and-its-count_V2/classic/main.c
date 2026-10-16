/* CULEGERE VI.3.11 - THE MINIMUM AND HOW OFTEN IT APPEARS (V2)
 * N NUMBERS ARE GIVEN; FIND THE SMALLEST VALUE AND PRINT HOW MANY TIMES IT APPEARS
 * EXAMPLE: N=8, 6 4 7 5 8 5 9 5 -> MIN=4 APPEARS 1 TIME
 * NOTE: THE BOOK'S EXAMPLE SAYS MIN=5 APPEARS 3 TIMES; THE CORRECT RESULT IS MIN=4 APPEARS 1 TIME
 * IMPROVEMENT: ONE PASS: A SMALLER VALUE RESTARTS THE COUNT FROM 1, AN EQUAL VALUE ADDS 1 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i, min, count;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	min = a[0]; /* SO FAR THE FIRST NUMBER IS THE MINIMUM, SEEN ONCE */
	count = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i] < min) /* A NEW, SMALLER MINIMUM: START COUNTING AGAIN */
		{
			min = a[i];
			count = 1;
		}
		else if (a[i] == min) /* ONE MORE APPEARANCE OF THE MINIMUM */
		{
			count++;
		}
	}

	printf("min=%d appears %d %s\n", min, count, (count == 1) ? "time" : "times");

	return 0;
}
