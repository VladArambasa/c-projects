/* DECIMAL TO BINARY: DIVIDE BY 2 AND COLLECT THE REMAINDERS, THEN READ THEM BACKWARDS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	int bits[32]; /* AN INT HAS AT MOST 32 BITS HERE */
	int count = 0;

	printf("Enter a positive number: ");
	scanf("%d", &n);

	if (n == 0)
	{
		bits[count] = 0; /* 0 IS SIMPLY 0 */
		count++;
	}

	while (n > 0)
	{
		bits[count] = n % 2; /* THE REMAINDER IS THE NEXT BIT, FROM THE RIGHT */
		count++;
		n = n / 2;
	}

	printf("Binary: ");
	for (i = count - 1; i >= 0; i--) /* LAST REMAINDER FIRST */
	{
		printf("%d", bits[i]);
	}
	printf("\n");

	return 0;
}
