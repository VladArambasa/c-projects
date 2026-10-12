/* CULEGERE XI.2.2 - LARGEST AND SMALLEST DIGIT
 * READ N INTEGERS; PRINT THE LARGEST DIGIT OF THE NUMBERS ON EVEN POSITIONS AND THE SMALLEST DIGIT
 * OF THE NUMBERS ON ODD POSITIONS, WITH ONE FUNCTION FOR THE LARGEST AND ONE FOR THE SMALLEST DIGIT
 * EXAMPLE: 123 45 907 61 58 -> LARGEST DIGIT (EVEN POSITIONS): 6, SMALLEST DIGIT (ODD POSITIONS): 0
 * ASSUMPTION: POSITIONS ARE COUNTED FROM 1; ONE DIGIT IS PRINTED FOR ALL THE EVEN POSITIONS
 * TOGETHER AND ONE FOR ALL THE ODD POSITIONS TOGETHER */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* THE LARGEST DIGIT OF X */
int max_digit(int x)
{
	int max = 0;

	if (x < 0) /* THE MINUS SIGN IS NOT A DIGIT */
	{
		x = -x;
	}
	do /* DO-WHILE: EVEN THE NUMBER 0 HAS ONE DIGIT */
	{
		if (x % 10 > max)
		{
			max = x % 10;
		}
		x = x / 10;
	} while (x > 0);
	return max;
}

/* THE SMALLEST DIGIT OF X */
int min_digit(int x)
{
	int min = 9;

	if (x < 0)
	{
		x = -x;
	}
	do
	{
		if (x % 10 < min)
		{
			min = x % 10;
		}
		x = x / 10;
	} while (x > 0);
	return min;
}

int main(void)
{
	int n = 0, i, x = 0, digit, max = -1, min = 10;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (i % 2 == 0) /* EVEN POSITION: COMPARE ITS LARGEST DIGIT */
		{
			digit = max_digit(x);
			if (digit > max)
			{
				max = digit;
			}
		}
		else /* ODD POSITION: COMPARE ITS SMALLEST DIGIT */
		{
			digit = min_digit(x);
			if (digit < min)
			{
				min = digit;
			}
		}
	}

	if (max == -1) /* ONLY ONE NUMBER: THERE IS NO EVEN POSITION */
	{
		printf("No numbers on even positions\n");
	}
	else
	{
		printf("Largest digit (even positions): %d\n", max);
	}
	printf("Smallest digit (odd positions): %d\n", min);

	return 0;
}
