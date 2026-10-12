/* STRONG NUMBER: EQUALS THE SUM OF THE FACTORIALS OF ITS DIGITS (145 = 1! + 4! + 5!) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, temp, i;
	int sum = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	temp = n;
	while (temp > 0)
	{
		int digit = temp % 10;
		int fact = 1;

		for (i = 2; i <= digit; i++) /* FACTORIAL OF THIS DIGIT */
		{
			fact = fact * i;
		}
		sum = sum + fact;
		temp = temp / 10;
	}

	if (n > 0 && sum == n)
	{
		printf("%d is a strong number\n", n);
	}
	else
	{
		printf("%d is not a strong number\n", n);
	}

	return 0;
}
