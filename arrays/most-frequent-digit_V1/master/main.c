/* THE DIGIT THAT APPEARS MOST OFTEN IN A NUMBER: COUNT EACH DIGIT 0..9 SEPARATELY */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	long long n = 0, copy;
	int digit, count;
	int best_digit = 0, best_count = 0;

	printf("Enter a number: ");
	scanf("%lld", &n);
	if (n < 0)
	{
		n = -n;
	}

	for (digit = 0; digit <= 9; digit++) /* ONE PASS OVER THE NUMBER FOR EACH DIGIT */
	{
		count = 0;
		copy = n;
		do
		{
			if (copy % 10 == digit)
			{
				count++;
			}
			copy = copy / 10;
		} while (copy > 0);

		if (count > best_count) /* ON A TIE THE SMALLER DIGIT STAYS */
		{
			best_count = count;
			best_digit = digit;
		}
	}

	printf("Digit %d appears %d time(s)\n", best_digit, best_count);

	return 0;
}
