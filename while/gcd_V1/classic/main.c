/* GREATEST COMMON DIVISOR: START FROM THE SMALLER NUMBER AND GO DOWN UNTIL BOTH ARE DIVISIBLE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, d;

	printf("Enter two positive numbers: ");
	scanf("%d %d", &a, &b);

	if (a <= 0 || b <= 0)
	{
		printf("Please enter positive numbers\n");
		return 1;
	}

	if (a < b) /* THE GCD CANNOT BE LARGER THAN THE SMALLER NUMBER */
	{
		d = a;
	}
	else
	{
		d = b;
	}

	while (a % d != 0 || b % d != 0) /* NOT A COMMON DIVISOR YET */
	{
		d--;
	}

	printf("GCD = %d\n", d);

	return 0;
}
