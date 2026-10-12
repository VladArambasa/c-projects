/* GCD WITH A RECURSIVE FUNCTION, THEN LCM = A / GCD * B */
#include <stdio.h> /* PRINTF, SCANF */

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b); /* EUCLID: GCD(A, B) = GCD(B, A % B) */
}

int main(void)
{
	int a = 0, b = 0;

	printf("Enter two positive numbers: ");
	scanf("%d %d", &a, &b);

	if (a <= 0 || b <= 0)
	{
		printf("Please enter positive numbers\n");
		return 1;
	}

	printf("GCD = %d\n", gcd(a, b));
	printf("LCM = %d\n", a / gcd(a, b) * b); /* DIVIDE FIRST TO KEEP THE NUMBERS SMALL */

	return 0;
}
