/* INFINITE LOOP WITH BREAK: LOOP FOREVER AND LEAVE FROM THE MIDDLE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;
	int sum = 0, count = 0;

	while (1) /* 1 IS ALWAYS TRUE; FOR ( ; ; ) WORKS THE SAME */
	{
		printf("Enter a number (negative to stop): ");
		if (scanf("%d", &n) != 1 || n < 0) /* NEGATIVE NUMBER OR END OF INPUT */
		{
			break; /* THE ONLY WAY OUT */
		}
		sum = sum + n;
		count++;
	}

	printf("\nYou entered %d numbers, their sum is %d\n", count, sum);

	return 0;
}
