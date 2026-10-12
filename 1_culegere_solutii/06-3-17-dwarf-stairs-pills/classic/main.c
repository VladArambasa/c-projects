/* CULEGERE VI.3.17 - THE DWARF ON THE STAIRS
 * A DWARF CLIMBS N STEPS WHOSE HEIGHTS (WHOLE CM, THE FIRST ONE 0) ARE IN INCREASING ORDER.
 * A STEP 1 CM ABOVE THE PREVIOUS ONE IS EASY; FOR A BIGGER DIFFERENCE HE NEEDS A PILL TO JUMP.
 * PRINT THE MINIMUM NUMBER OF PILLS AND THE BIGGEST DIFFERENCE BETWEEN TWO CONSECUTIVE STEPS
 * EXAMPLE: N=9, 0 3 4 6 7 10 19 20 21 -> MINIMUM NUMBER OF PILLS=4   MAXIMUM DIFFERENCE=9 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int h[MAX] = {0};
	int n = 0, i, diff;
	int pills = 0, max_diff = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d step heights: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
	}

	for (i = 1; i < n; i++) /* COMPARE EVERY STEP WITH THE ONE BELOW IT */
	{
		diff = h[i] - h[i - 1];
		if (diff > 1) /* TOO HIGH TO CLIMB: ONE PILL FOR THIS JUMP */
		{
			pills++;
		}
		if (diff > max_diff)
		{
			max_diff = diff;
		}
	}

	printf("minimum number of pills=%d   maximum difference=%d\n", pills, max_diff);

	return 0;
}
