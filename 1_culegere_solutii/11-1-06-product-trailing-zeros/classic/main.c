/* CULEGERE XI.1.6 - ZEROS AT THE END OF A PRODUCT
 * READ TWO INTEGERS; PRINT HOW MANY ZEROS THEIR PRODUCT ENDS WITH, WITHOUT COMPUTING THE PRODUCT
 * EVERY FINAL ZERO COMES FROM A 2 TIMES A 5 IN THE PRIME FACTORS OF THE TWO NUMBERS; A PROCEDURE
 * WITH TWO PARAMETERS FINDS THE EXPONENT OF A PRIME IN THE PRIME FACTORIZATION OF A NUMBER
 * EXAMPLE: 125 AND 16 -> 3 (125 * 16 = 2000)
 * ASSUMPTION: WITH BOTH PARAMETERS TAKEN, THE PROCEDURE GIVES ITS ANSWER IN A GLOBAL VARIABLE
 * ASSUMPTION: IF ONE OF THE NUMBERS IS 0, THE PRODUCT IS 0 AND THE PROGRAM JUST SAYS SO */
#include <stdio.h> /* PRINTF, SCANF */

int exponent; /* THE ANSWER OF PRIME_EXPONENT: A VOID FUNCTION CANNOT RETURN IT */

/* THE PROCEDURE: HOW MANY TIMES DOES THE PRIME P DIVIDE X? */
void prime_exponent(int x, int p)
{
	exponent = 0;
	while (x % p == 0) /* DIVIDE BY P AS LONG AS IT GOES */
	{
		x = x / p;
		exponent++;
	}
}

int main(void)
{
	int a = 0, b = 0, twos, fives;

	printf("Two integers: ");
	scanf("%d %d", &a, &b);

	if (a == 0 || b == 0) /* 0 CAN BE DIVIDED BY 2 FOREVER */
	{
		printf("The product is 0\n");
		return 0;
	}

	prime_exponent(a, 2); /* THE FACTORS 2 OF A AND OF B */
	twos = exponent;
	prime_exponent(b, 2);
	twos = twos + exponent;

	prime_exponent(a, 5); /* THE FACTORS 5 OF A AND OF B */
	fives = exponent;
	prime_exponent(b, 5);
	fives = fives + exponent;

	/* EVERY PAIR (2, 5) GIVES ONE ZERO, SO THE SMALLER COUNT DECIDES */
	if (twos < fives)
	{
		printf("Zeros at the end of the product: %d\n", twos);
	}
	else
	{
		printf("Zeros at the end of the product: %d\n", fives);
	}

	return 0;
}
