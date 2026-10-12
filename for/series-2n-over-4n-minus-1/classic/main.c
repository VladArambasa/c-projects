/* SUM OF THE SERIES 2/3 + 4/7 + 6/11 + 8/15 + ... UP TO N TERMS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	double sum = 0;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) /* TERM I IS 2I / (4I - 1) */
	{
		sum = sum + (2.0 * i) / (4.0 * i - 1);
	}

	printf("Sum = %.4f\n", sum);

	return 0;
}
