/* CULEGERE III.7.6 - PALINDROME NUMBER
 * CHECK WHETHER A NUMBER READS THE SAME FROM LEFT TO RIGHT AND FROM RIGHT TO LEFT
 * ASSUMPTION: A NATURAL NUMBER WITH AT MOST 9 DIGITS, SO ITS REVERSE ALSO FITS IN AN INT
 * EXAMPLES: 12321 -> YES; 23034 -> NO */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, copy;
	int reversed = 0;

	printf("n = ");
	scanf("%d", &n);

	copy = n; /* THE LOOP DESTROYS COPY, SO N KEEPS THE ORIGINAL */
	while (copy > 0)
	{
		/* THE LAST DIGIT OF COPY IS ADDED AT THE END OF REVERSED */
		reversed = reversed * 10 + copy % 10;
		copy = copy / 10;
	}

	if (reversed == n)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
