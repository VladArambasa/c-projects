/* CULEGERE II.5.3 - LARGEST EVEN NUMBER OF TWO
 * READ TWO NUMBERS AND PRINT THE LARGEST EVEN NUMBER AMONG THEM
 * EXAMPLES: 23 45 -> THERE IS NO EVEN NUMBER; 28 14 -> 28; 77 4 -> 4 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	if (a % 2 == 0 && b % 2 == 0) /* BOTH EVEN: THE BIGGER ONE */
	{
		if (a > b)
		{
			printf("%d\n", a);
		}
		else
		{
			printf("%d\n", b);
		}
	}
	else if (a % 2 == 0) /* ONLY A IS EVEN */
	{
		printf("%d\n", a);
	}
	else if (b % 2 == 0) /* ONLY B IS EVEN */
	{
		printf("%d\n", b);
	}
	else
	{
		printf("There is no even number\n");
	}

	return 0;
}
