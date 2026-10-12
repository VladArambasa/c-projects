/* CULEGERE VI.4.7 - COUNT PRIZE WINNERS
 * THE SCORES OF N PUPILS ARE READ (N <= 300, EVERY SCORE IS A NATURAL NUMBER <= 100). TWO PUPILS
 * GET THE SAME PRIZE ONLY IF THEIR SCORES ARE EQUAL: THE HIGHEST SCORE GETS PRIZE I, THE NEXT
 * DIFFERENT SCORE GETS PRIZE II, THE NEXT ONE PRIZE III. PRINT, ONE PER LINE, HOW MANY PUPILS
 * GET EACH PRIZE
 * V1: SORT THE SCORES IN DESCENDING ORDER, THEN COUNT THE FIRST THREE GROUPS OF EQUAL SCORES
 * ASSUMPTION: WITH FEWER THAN THREE DIFFERENT SCORES, A PRIZE NOBODY GETS IS PRINTED AS 0
 * EXAMPLE: N=10, 58 79 34 12 58 40 79 58 30 58 -> 2 4 1 (ONE NUMBER PER LINE) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 300 /* N <= 300 */

int main(void)
{
	int a[MAX];
	int prizes[4] = {0}; /* PRIZES[1], PRIZES[2], PRIZES[3]; PRIZES[0] IS NOT USED */
	int n = 0, i, j, temp, prize;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d scores: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* BUBBLE SORT IN DESCENDING ORDER: THE HIGHEST SCORE GOES FIRST */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	prize = 1; /* THE FIRST PUPIL OF THE SORTED LIST GETS PRIZE I */
	prizes[1] = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1]) /* A LOWER SCORE STARTS THE NEXT PRIZE */
		{
			prize++;
		}
		if (prize <= 3) /* THE PUPILS AFTER PRIZE III GET NOTHING */
		{
			prizes[prize]++;
		}
	}

	printf("%d\n%d\n%d\n", prizes[1], prizes[2], prizes[3]);

	return 0;
}
