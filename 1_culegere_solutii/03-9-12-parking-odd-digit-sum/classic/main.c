/* CULEGERE III.9.12 - CARS IN THE PARKING LOT
 * N CARS (N <= 20) HAVE TEMPORARY PLATE NUMBERS (INTEGERS WITH AT MOST 5 DIGITS), READ
 * IN THE ORDER THE CARS ARE PARKED; PRINT THE POSITIONS OF THE CARS WHOSE PLATE NUMBER HAS AN
 * ODD SUM OF DIGITS
 * ASSUMPTION: A PLATE NUMBER IS NEVER NEGATIVE
 * EXAMPLE: N=5: 634 90281 63721 30361 70915 -> POSITIONS: 1 3 4 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 20 /* AT MOST 20 CARS */

int sum_of_digits(int x)
{
	int sum = 0;

	while (x > 0)
	{
		sum = sum + x % 10; /* ADD THE LAST DIGIT, THEN CUT IT OFF */
		x = x / 10;
	}
	return sum;
}

int main(void)
{
	int plate[MAX] = {0};
	int n = 0, i;
	int found = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d plate numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &plate[i]);
	}

	printf("Positions:");
	for (i = 0; i < n; i++)
	{
		if (sum_of_digits(plate[i]) % 2 == 1) /* ODD SUM OF DIGITS */
		{
			printf(" %d", i + 1); /* POSITIONS START AT 1, ARRAY INDEXES AT 0 */
			found++;
		}
	}
	if (found == 0)
	{
		printf(" none");
	}
	printf("\n");

	return 0;
}
