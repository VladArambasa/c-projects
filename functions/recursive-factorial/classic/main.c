/* RECURSION: A FUNCTION THAT CALLS ITSELF; N! = N * (N - 1)! */
#include <stdio.h> /* PRINTF, SCANF */

long long factorial(int n)
{
	if (n <= 1) /* STOP CONDITION: WITHOUT IT THE CALLS WOULD NEVER END */
	{
		return 1;
	}
	return n * factorial(n - 1); /* THE SAME PROBLEM, ONE STEP SMALLER */
}

int main(void)
{
	int n = 0;

	printf("Enter n (0-20): ");
	scanf("%d", &n);

	if (n < 0 || n > 20)
	{
		printf("n must be between 0 and 20\n");
		return 1;
	}

	printf("%d! = %lld\n", n, factorial(n));

	return 0;
}
