/* CULEGERE XIII.1.8 - SMALLEST FRACTIONS
 * WITH TWO DIFFERENT NUMBERS OUT OF FOUR NATURAL NUMBERS A, B, C, D (ONE AS NUMERATOR, THE OTHER AS
 * DENOMINATOR), FIND THE SMALLEST FRACTION LESS THAN 1 AND THE SMALLEST FRACTION GREATER THAN 1,
 * AND PRINT THEM IN LOWEST TERMS
 * EXAMPLE: A=2 B=5 C=6 D=16 -> 1/8 (FROM 2/16) AND 6/5
 * ASSUMPTION: THE NUMBERS ARE NOT 0 AND ARE SMALLER THAN 32768, SO THE CROSS PRODUCTS
 *   FIT IN AN INT */
#include <stdio.h> /* PRINTF, SCANF */

/* GREATEST COMMON DIVISOR, BY EUCLID */
int gcd(int a, int b)
{
	int r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void)
{
	int v[4];
	int a = 0, b = 0, c = 0, d = 0, i, j, p, q, g;
	int found_less = 0, less_p = 0, less_q = 1;          /* SMALLEST FRACTION BELOW 1 SO FAR */
	int found_greater = 0, greater_p = 0, greater_q = 1; /* SMALLEST FRACTION ABOVE 1 SO FAR */

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	printf("d = ");
	scanf("%d", &d);
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = d;

	/* EVERY ORDERED PAIR OF TWO DIFFERENT NUMBERS GIVES A FRACTION P/Q
	 * P/Q < LESS_P/LESS_Q IS THE SAME AS P * LESS_Q < LESS_P * Q, SO NO DIVISION IS NEEDED */
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (i != j)
			{
				p = v[i];
				q = v[j];
				if (p < q && (found_less == 0 || p * less_q < less_p * q))
				{
					less_p = p;
					less_q = q;
					found_less = 1;
				}
				if (p > q && (found_greater == 0 || p * greater_q < greater_p * q))
				{
					greater_p = p;
					greater_q = q;
					found_greater = 1;
				}
			}
		}
	}

	if (found_less == 1)
	{
		g = gcd(less_p, less_q); /* LOWEST TERMS */
		printf("Smallest fraction less than 1: %d/%d\n", less_p / g, less_q / g);
	}
	else
	{
		printf("No fraction is less than 1\n");
	}
	if (found_greater == 1)
	{
		g = gcd(greater_p, greater_q);
		printf("Smallest fraction greater than 1: %d/%d\n", greater_p / g, greater_q / g);
	}
	else
	{
		printf("No fraction is greater than 1\n");
	}

	return 0;
}
