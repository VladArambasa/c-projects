/* ELECTRICITY BILL: UNITS 1-100 COST 5, 101-200 COST 7, 201-300 COST 10, ABOVE 300 COST 12 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int units = 0, bill;

	printf("Enter the units consumed: ");
	scanf("%d", &units);

	if (units <= 100)
	{
		bill = units * 5;
	}
	else if (units <= 200)
	{
		bill = 100 * 5 + (units - 100) * 7; /* FIRST 100 UNITS + THE REST */
	}
	else if (units <= 300)
	{
		bill = 100 * 5 + 100 * 7 + (units - 200) * 10;
	}
	else
	{
		bill = 100 * 5 + 100 * 7 + 100 * 10 + (units - 300) * 12;
	}

	printf("Bill: %d\n", bill);

	return 0;
}
