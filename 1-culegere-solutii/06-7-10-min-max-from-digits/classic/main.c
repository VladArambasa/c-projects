/* CULEGERE VI.7.10 - SMALLEST AND LARGEST FROM THE DIGITS
 * A NATURAL NUMBER WITH NON-ZERO DIGITS IS READ; PRINT THE SMALLEST AND THE LARGEST NUMBER THAT
 * CAN BE WRITTEN WITH ITS DIGITS
 * ASSUMPTION: THE NUMBER HAS AT MOST 18 DIGITS, SO EVERY RESULT FITS IN A LONG LONG
 * EXAMPLE: N=26341 -> MIN=12346 MAX=64321 */
#include <stdio.h> /* PRINTF, SCANF */

#define DIGITS 18 /* AT MOST 18 DIGITS */

int main(void)
{
	long long n = 0, min, max; /* LONG LONG: THE LARGEST NUMBER CAN BE TOO BIG FOR AN INT */
	int digit[DIGITS];
	int count, i, j, temp;

	printf("n = ");
	scanf("%lld", &n); /* %LLD READS A LONG LONG */

	/* PUT THE DIGITS OF N INTO A VECTOR, FROM THE LAST DIGIT TO THE FIRST */
	count = 0;
	while (n > 0)
	{
		digit[count] = n % 10;
		count++;
		n = n / 10;
	}

	/* BUBBLE SORT OF THE DIGITS, IN ASCENDING ORDER */
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (digit[j] > digit[j + 1])
			{
				temp = digit[j];
				digit[j] = digit[j + 1];
				digit[j + 1] = temp;
			}
		}
	}

	/* THE SMALLEST NUMBER: THE DIGITS FROM THE SMALLEST TO THE LARGEST */
	min = 0;
	for (i = 0; i < count; i++)
	{
		min = min * 10 + digit[i]; /* THE DIGIT IS ADDED AT THE RIGHT END */
	}

	/* THE LARGEST NUMBER: THE SAME DIGITS, FROM THE LARGEST TO THE SMALLEST */
	max = 0;
	for (i = count - 1; i >= 0; i--)
	{
		max = max * 10 + digit[i];
	}

	printf("min=%lld max=%lld\n", min, max);

	return 0;
}
