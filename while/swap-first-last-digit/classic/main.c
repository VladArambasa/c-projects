/* SWAP THE FIRST AND THE LAST DIGIT OF A NUMBER (12345 -> 52341) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, first, last, middle, result;
	int power = 1; /* 10 TO THE POWER (NUMBER OF DIGITS - 1) */

	printf("Enter a positive number: ");
	scanf("%d", &n);

	last = n % 10;
	first = n;
	while (first >= 10) /* DIVIDE UNTIL ONLY THE FIRST DIGIT IS LEFT */
	{
		first = first / 10;
		power = power * 10;
	}

	if (power == 1) /* ONE DIGIT: NOTHING TO SWAP */
	{
		printf("Result: %d\n", n);
		return 0;
	}

	middle = (n % power) / 10; /* THE DIGITS BETWEEN THE FIRST AND THE LAST */
	result = last * power + middle * 10 + first;

	printf("Result: %d\n", result);

	return 0;
}
