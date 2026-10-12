/* INPUT VALIDATION: KEEP ASKING UNTIL THE NUMBER IS BETWEEN 1 AND 10 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;

	do
	{
		printf("Enter a number between 1 and 10: ");
		if (scanf("%d", &n) != 1) /* NOT A NUMBER, OR NO MORE INPUT */
		{
			printf("\nNo valid number given. Bye!\n");
			return 1;
		}
	} while (n < 1 || n > 10); /* WRONG VALUE: ASK AGAIN */

	printf("Thank you, you entered %d\n", n);

	return 0;
}
