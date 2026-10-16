/* CULEGERE XI.1.4 - SUM OF TWO FRACTIONS
 * READ THE NUMERATOR AND THE DENOMINATOR OF TWO FRACTIONS; PRINT THE TWO FRACTIONS AND THEIR SUM IN
 * LOWEST TERMS, USING A PROCEDURE WITH TWO PARAMETERS THAT SIMPLIFIES A FRACTION
 * EXAMPLE: 2/8 AND 6/9 -> 1/4 + 2/3 = 11/12
 * ASSUMPTION: THE NUMBERS ARE NATURAL AND THE DENOMINATORS ARE NOT 0 */
#include <stdio.h> /* PRINTF, SCANF */

/* THE PROCEDURE: DIVIDES THE NUMERATOR AND THE DENOMINATOR BY THEIR GREATEST COMMON DIVISOR
 * IT RECEIVES THE ADDRESSES OF THE TWO VARIABLES, SO IT CAN CHANGE THEM */
void simplify(int *num, int *den)
{
	int a = *num, b = *den, r;

	while (b != 0) /* EUCLID: THE LAST NON-ZERO REMAINDER IS THE GREATEST COMMON DIVISOR */
	{
		r = a % b;
		a = b;
		b = r;
	}
	*num = *num / a;
	*den = *den / a;
}

int main(void)
{
	int a = 0, b = 0, c = 0, d = 0, num, den;

	printf("First fraction (numerator and denominator): ");
	scanf("%d %d", &a, &b);
	printf("Second fraction (numerator and denominator): ");
	scanf("%d %d", &c, &d);

	simplify(&a, &b);
	simplify(&c, &d);

	num = a * d + c * b; /* A/B + C/D = (A*D + C*B) / (B*D) */
	den = b * d;
	simplify(&num, &den);

	printf("%d/%d + %d/%d = %d/%d\n", a, b, c, d, num, den);

	return 0;
}
