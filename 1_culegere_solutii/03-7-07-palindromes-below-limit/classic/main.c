/* CULEGERE III.7.7 - PALINDROMES BETWEEN 10 AND N
 * PRINT ALL THE PALINDROME NUMBERS (THE SAME READ FROM BOTH ENDS) GREATER THAN 10
 * AND SMALLER THAN A GIVEN NUMBER N
 * EXAMPLE: N=110 -> 11 22 33 44 55 66 77 88 99 101 */
#include <stdio.h> /* PRINTF, SCANF */

int is_palindrome(int x) /* 1 IF X READS THE SAME BACKWARDS, 0 OTHERWISE */
{
	int copy = x, reversed = 0;

	while (copy > 0)
	{
		reversed = reversed * 10 + copy % 10; /* THE LAST DIGIT OF COPY GOES TO REVERSED */
		copy = copy / 10;
	}

	if (reversed == x)
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	int n = 0, i;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);

	for (i = 11; i < n; i++) /* GREATER THAN 10 AND SMALLER THAN N */
	{
		if (is_palindrome(i) == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	if (count == 0)
	{
		printf("None");
	}
	printf("\n");

	return 0;
}
