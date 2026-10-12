/* SUM OF NUMBERS: KEEP READING UNTIL 0 IS ENTERED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;
	int sum = 0;

	do
	{
		printf("Enter a number (0 to stop): ");
		if (scanf("%d", &n) != 1)
		{
			n = 0; /* NO MORE INPUT: STOP AS IF 0 WAS TYPED */
		}
		sum = sum + n;
	} while (n != 0);

	printf("Sum = %d\n", sum);

	return 0;
}
