/* PERFECT NUMBER (V2): A DIVISOR SMALLER THAN N IS AT MOST N / 2, SO THE LOOP DOES HALF THE WORK */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	int sum = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 1; i <= n / 2; i++) /* NOTHING BETWEEN N / 2 AND N CAN DIVIDE N */
	{
		if (n % i == 0)
		{
			sum = sum + i;
		}
	}

	if (n > 0 && sum == n)
	{
		printf("%d is a perfect number\n", n);
	}
	else
	{
		printf("%d is not a perfect number\n", n);
	}

	return 0;
}
