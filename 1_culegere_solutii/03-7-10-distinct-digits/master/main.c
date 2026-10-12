/* CULEGERE III.7.10 - DISTINCT DIGITS
 * PRINT HOW MANY DIFFERENT DIGITS A NON-ZERO NATURAL NUMBER CONTAINS
 * EXAMPLE: 234323 -> 3 DISTINCT DIGITS (2, 3 AND 4) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, digit;
	int seen[10] = {0}; /* SEEN[D] BECOMES 1 WHEN DIGIT D IS FOUND */
	int count = 0;

	printf("n = ");
	scanf("%d", &n);

	while (n > 0)
	{
		digit = n % 10;
		if (seen[digit] == 0) /* A DIGIT MET FOR THE FIRST TIME */
		{
			seen[digit] = 1;
			count++;
		}
		n = n / 10;
	}

	printf("%d distinct %s\n", count, (count == 1) ? "digit" : "digits");

	return 0;
}
