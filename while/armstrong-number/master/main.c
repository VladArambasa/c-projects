/* ARMSTRONG NUMBER: EQUALS THE SUM OF ITS DIGITS, EACH RAISED TO THE NUMBER OF DIGITS
 * EXAMPLE: 153 = 1*1*1 + 5*5*5 + 3*3*3 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, temp, i;
	int digits = 0;
	int sum = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	temp = n; /* 1. COUNT THE DIGITS */
	while (temp > 0)
	{
		digits++;
		temp = temp / 10;
	}

	temp = n; /* 2. ADD EVERY DIGIT RAISED TO THAT POWER */
	while (temp > 0)
	{
		int digit = temp % 10;
		int power = 1;

		for (i = 0; i < digits; i++)
		{
			power = power * digit;
		}
		sum = sum + power;
		temp = temp / 10;
	}

	if (sum == n)
	{
		printf("%d is an Armstrong number\n", n);
	}
	else
	{
		printf("%d is not an Armstrong number\n", n);
	}

	return 0;
}
