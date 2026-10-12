/* LEAP YEAR: DIVISIBLE BY 4 BUT NOT BY 100, OR DIVISIBLE BY 400 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int year = 0;

	printf("Enter a year: ");
	scanf("%d", &year);

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d is a leap year\n", year);
	}
	else
	{
		printf("%d is not a leap year\n", year);
	}

	return 0;
}
