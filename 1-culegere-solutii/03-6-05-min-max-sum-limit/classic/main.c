/* CULEGERE III.6.5 - MIN AND MAX WHILE THE SUM STAYS UP TO 1000
 * POSITIVE INTEGERS ARE READ AS LONG AS THEIR SUM DOES NOT EXCEED 1000;
 * PRINT THE LARGEST AND THE SMALLEST OF THESE NUMBERS
 * ASSUMPTION: THE NUMBER THAT WOULD TAKE THE SUM PAST 1000 IS NOT COUNTED (45 IN THE EXAMPLE)
 * EXAMPLE: 550 345 100 45 -> MAX=550 MIN=100 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int x = 0;
	int sum = 0, count = 0;
	int max = 0;    /* SMALLER THAN ANY POSITIVE NUMBER */
	int min = 1001; /* EVERY COUNTED NUMBER IS AT MOST 1000, SO IT IS SMALLER THAN THIS */

	printf("Positive numbers (keep typing until their sum goes over 1000): ");
	/* STOP WHEN THE NEW NUMBER WOULD TAKE THE SUM PAST 1000 (OR WHEN THE INPUT ENDS) */
	while (scanf("%d", &x) == 1 && sum + x <= 1000)
	{
		sum = sum + x;
		count++;
		if (x > max)
		{
			max = x;
		}
		if (x < min)
		{
			min = x;
		}
	}

	if (count == 0)
	{
		printf("No numbers: the first one is already over 1000\n");
	}
	else
	{
		printf("max=%d min=%d\n", max, min);
	}

	return 0;
}
