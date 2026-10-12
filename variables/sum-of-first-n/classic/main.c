/* SUM OF THE FIRST N NATURAL NUMBERS: 1 + 2 + ... + N = N * (N + 1) / 2 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	long long n = 0; /* LONG LONG: N * (N + 1) GROWS FAST */

	printf("Enter n: ");
	scanf("%lld", &n);

	printf("Sum = %lld\n", n * (n + 1) / 2); /* GAUSS FORMULA: NO LOOP NEEDED */

	return 0;
}
