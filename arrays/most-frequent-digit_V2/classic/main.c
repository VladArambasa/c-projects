/* THE DIGIT THAT APPEARS MOST OFTEN (V2): ONE PASS FILLS A TABLE OF 10 COUNTERS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	long long n = 0;
	int count[10] = {0}; /* COUNT[D] = HOW MANY TIMES DIGIT D WAS SEEN */
	int digit, best_digit = 0;

	printf("Enter a number: ");
	scanf("%lld", &n);
	if (n < 0)
	{
		n = -n;
	}

	do
	{
		count[n % 10]++; /* THE DIGIT ITSELF IS THE INDEX */
		n = n / 10;
	} while (n > 0);

	for (digit = 1; digit <= 9; digit++)
	{
		if (count[digit] > count[best_digit])
		{
			best_digit = digit;
		}
	}

	printf("Digit %d appears %d time(s)\n", best_digit, count[best_digit]);

	return 0;
}
