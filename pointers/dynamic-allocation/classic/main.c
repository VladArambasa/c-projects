/* DYNAMIC MEMORY: MALLOC RESERVES MEMORY WHILE THE PROGRAM RUNS, FREE GIVES IT BACK */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* MALLOC, FREE */

int main(void)
{
	int n = 0, i;
	int *numbers;
	int sum = 0;

	printf("How many numbers? ");
	scanf("%d", &n);
	if (n < 1)
	{
		printf("Invalid size\n");
		return 1;
	}

	numbers = malloc(n * sizeof(int)); /* ROOM FOR N INTS, N KNOWN ONLY NOW */
	if (numbers == NULL)               /* MALLOC RETURNS NULL WHEN THERE IS NO MEMORY */
	{
		printf("Not enough memory\n");
		return 1;
	}

	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]); /* USED EXACTLY LIKE AN ARRAY */
		sum = sum + numbers[i];
	}

	printf("Sum = %d, average = %.2f\n", sum, (double)sum / n);

	free(numbers); /* EVERY MALLOC NEEDS ITS FREE */

	return 0;
}
