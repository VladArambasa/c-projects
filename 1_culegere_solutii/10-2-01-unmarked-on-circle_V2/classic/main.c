/* CULEGERE X.2.1 - UNMARKED NUMBERS ON A CIRCLE (V2)
 * THE NUMBERS 1..N STAND IN INCREASING ORDER ON A CIRCLE, SO N IS NEXT TO 1. STARTING WITH
 * THE NUMBER S, EVERY K-TH NUMBER IS MARKED, GOING UP, UNTIL A NUMBER IS MARKED A SECOND TIME.
 * HOW MANY NUMBERS STAY UNMARKED?
 * EXAMPLE: N = 12, S = 1, K = 4 -> 1, 5, 9 ARE MARKED, THEN 1 AGAIN -> 9 UNMARKED NUMBERS
 * V2: A FORMULA REPLACES THE WALK: EXACTLY N / GCD(N, K) NUMBERS GET MARKED, WHATEVER S IS */
#include <stdio.h> /* PRINTF, SCANF */

/* GREATEST COMMON DIVISOR, BY EUCLID'S ALGORITHM */
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
	int n = 0, s = 0, k = 0, marked;

	printf("n = ");
	scanf("%d", &n);
	printf("s = ");
	scanf("%d", &s);
	printf("k = ");
	scanf("%d", &k);

	/* THE FIRST NUMBER MARKED TWICE IS ALWAYS S ITSELF: AFTER J JUMPS WE ARE BACK ON S
	 * WHEN J * K IS A MULTIPLE OF N, AND THE SMALLEST SUCH J IS N / GCD(N, K);
	 * SO S DOES NOT CHANGE THE ANSWER */
	marked = n / gcd(n, k);

	printf("Unmarked numbers: %d\n", n - marked);

	return 0;
}
