/* CULEGERE III.7.8 - DIGITS IN DESCENDING ORDER
 * A NUMBER WITH AT MOST 8 DIGITS, ALL DIFFERENT AND FROM 1 TO 8, IS READ; PRINT ITS DIGITS
 * IN DESCENDING ORDER. THE BOOK'S METHOD: EVERY DIGIT C IS MULTIPLIED BY 10 TO THE POWER C,
 * THE RESULTS ARE ADDED, AND THE SUM IS PRINTED WITHOUT ITS ZEROS
 * EXAMPLE: 354 -> 4*10^4 + 5*10^5 + 3*10^3 = 543000 -> 543
 * NOTE: THE BOOK'S EXAMPLE SAYS THE SUM IS 54300; THE CORRECT RESULT IS 543000
 *       (THE PRINTED ANSWER IS 543 EITHER WAY) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int power_of_10(int c) /* 10 * 10 * ... * 10, C TIMES */
{
	int p = 1, i;

	for (i = 1; i <= c; i++)
	{
		p = p * 10;
	}
	return p;
}

int main(void)
{
	int n = 0, digit;
	int sum = 0;    /* DIGIT C GOES TO PLACE C OF SUM: BIGGER DIGITS GO FURTHER LEFT */
	int result = 0; /* SUM WITHOUT ITS ZEROS */
	int place = 1;  /* THE VALUE OF THE NEXT PLACE IN RESULT: 1, 10, 100... */

	printf("n = ");
	scanf("%d", &n);

	while (n > 0)
	{
		digit = n % 10;
		sum = sum + digit * power_of_10(digit);
		n = n / 10;
	}

	/* COPY THE NON-ZERO DIGITS OF SUM INTO RESULT, KEEPING THEIR ORDER */
	while (sum > 0)
	{
		digit = sum % 10;
		if (digit != 0)
		{
			result = result + digit * place;
			place = place * 10;
		}
		sum = sum / 10;
	}

	printf("%d\n", result);

	return 0;
}
