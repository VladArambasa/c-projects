/* CULEGERE XI.1.3 - THE FIRST N PRIMES
 * LIST THE FIRST N PRIME NUMBERS; A PROCEDURE WITH ONE PARAMETER CHECKS WHETHER A NUMBER IS PRIME
 * EXAMPLE: N=6 -> 2 3 5 7 11 13
 * ASSUMPTION: WITH ITS ONLY PARAMETER TAKEN, THE PROCEDURE GIVES ITS ANSWER IN A GLOBAL VARIABLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int prime; /* THE ANSWER OF CHECK_PRIME (1 = PRIME): A VOID FUNCTION CANNOT RETURN IT */

/* THE PROCEDURE: SETS PRIME TO 1 IF X IS PRIME, TO 0 OTHERWISE */
void check_prime(int x)
{
	int d;

	prime = 1;
	if (x < 2)
	{
		prime = 0;
	}
	for (d = 2; d * d <= x && prime == 1; d++) /* DIVISORS UP TO THE SQUARE ROOT ARE ENOUGH */
	{
		if (x % d == 0)
		{
			prime = 0;
		}
	}
}

int main(void)
{
	int n = 0, count = 0, x = 2;

	printf("n = ");
	scanf("%d", &n);

	printf("Primes:");
	while (count < n) /* TRY 2, 3, 4, ... UNTIL N PRIMES ARE FOUND */
	{
		check_prime(x);
		if (prime == 1)
		{
			printf(" %d", x);
			count++;
		}
		x++;
	}
	printf("\n");

	return 0;
}
