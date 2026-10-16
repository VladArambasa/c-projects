/* CULEGERE III.7.11 - COMMON DIGITS AND THE LARGEST NUMBER
 * TWO NATURAL NUMBERS A AND B WITH AT MOST 9 DIGITS ARE READ.
 * A) PRINT THE DISTINCT DIGITS THAT APPEAR IN BOTH A AND B
 * B) PRINT THE LARGEST NUMBER THAT CAN BE WRITTEN WITH ALL THE DIGITS OF A AND B
 * EXAMPLE: A=2115 B=29025 -> A) 2 5  B) 955222110 */
#include <stdio.h> /* PRINTF, SCANF */

/* ADDS 1 TO COUNT[D] FOR EVERY DIGIT D OF X. AN ARRAY IS NOT COPIED INTO A FUNCTION,
 * SO THE FUNCTION FILLS THE CALLER'S ARRAY */
void count_digits(int x, int count[])
{
	do /* DO-WHILE: THE NUMBER 0 HAS THE DIGIT 0 */
	{
		count[x % 10]++;
		x = x / 10;
	} while (x > 0);
}

int main(void)
{
	int a = 0, b = 0, d, i;
	int count_a[10] = {0};
	int count_b[10] = {0};
	int common = 0;
	long long largest = 0; /* UP TO 18 DIGITS: TOO BIG FOR AN INT */

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	count_digits(a, count_a);
	count_digits(b, count_b);

	/* A) A DIGIT IS COMMON WHEN IT APPEARS IN BOTH NUMBERS */
	printf("a)");
	for (d = 0; d <= 9; d++)
	{
		if (count_a[d] > 0 && count_b[d] > 0)
		{
			printf(" %d", d);
			common++;
		}
	}
	if (common == 0)
	{
		printf(" none");
	}
	printf("\n");

	/* B) THE BIGGEST DIGITS GO FIRST: ALL THE 9S, THEN ALL THE 8S, AND SO ON DOWN TO THE 0S */
	for (d = 9; d >= 0; d--)
	{
		for (i = 1; i <= count_a[d] + count_b[d]; i++)
		{
			largest = largest * 10 + d; /* WRITE DIGIT D AT THE END OF LARGEST */
		}
	}
	printf("b) %lld\n", largest);

	return 0;
}
