/* SUM OF THE SERIES 1 + 3/4 + 5/6 + 7/8 + ... UP TO N TERMS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	double sum = 1; /* THE FIRST TERM IS 1 */

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	for (i = 2; i <= n; i++) /* TERM I IS (2I - 1) / (2I) */
	{
		sum = sum + (2.0 * i - 1) / (2.0 * i); /* 2.0 MAKES THE DIVISION REAL */
	}

	printf("Sum = %.4f\n", sum);

	return 0;
}
