/* CULEGERE XIII.1.7 - LAST DIGIT OF A SUM AND OF A POWER (V2)
 * READ N (N < 100) AND N NON-ZERO NATURAL NUMBERS SMALLER THAN 30000; PRINT
 * A) THE LAST DIGIT OF X[1] + X[2] + ... + X[N]
 * B) THE LAST DIGIT OF X[1] RAISED TO THE POWER X[2] + X[3] + ... + X[N]
 * EXAMPLE: 11 4 3 -> A) 8  B) 1  (11 + 4 + 3 = 18 AND 11^7 = 19487171)
 * V2: THE LAST DIGITS OF THE POWERS REPEAT EVERY 4 STEPS: AT MOST 4 MULTIPLICATIONS ARE NEEDED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int x[MAX + 1];
	int n = 0, i, sum = 0, exponent = 0, base, steps, last;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}

	for (i = 1; i <= n; i++) /* A) ONLY THE LAST DIGIT OF THE SUM IS KEPT */
	{
		sum = (sum + x[i]) % 10;
	}
	printf("a) %d\n", sum);

	for (i = 2; i <= n; i++) /* B) THE EXPONENT IS X[2] + ... + X[N] */
	{
		exponent = exponent + x[i];
	}
	base = x[1] % 10; /* THE LAST DIGIT OF A PRODUCT DEPENDS ONLY ON THE LAST DIGITS */

	/* THE LAST DIGITS OF BASE, BASE^2, BASE^3, ... REPEAT EVERY 4 POWERS
	 * (FOR 2 THEY ARE 2 4 8 6 2 4 8 6 ...), SO BASE^EXPONENT ENDS LIKE BASE^STEPS,
	 * WITH STEPS FROM 1 TO 4 (STEPS IS 0 ONLY WHEN THE EXPONENT IS 0) */
	steps = exponent % 4;
	if (steps == 0 && exponent > 0)
	{
		steps = 4;
	}
	last = 1;
	for (i = 1; i <= steps; i++)
	{
		last = last * base % 10;
	}
	printf("b) %d\n", last);

	return 0;
}
