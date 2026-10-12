/* POSITIVE, NEGATIVE OR ZERO, USING A NESTED IF */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n >= 0)
	{
		if (n == 0) /* AN IF INSIDE ANOTHER IF */
		{
			printf("Zero\n");
		}
		else
		{
			printf("Positive\n");
		}
	}
	else
	{
		printf("Negative\n");
	}

	return 0;
}
