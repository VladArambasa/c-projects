/* MONTH NAME AND NUMBER OF DAYS (V2): TWO TABLES REPLACE THE 12-CASE SWITCH */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char *names[12] = {"January", "February", "March", "April", "May", "June", "July",
	                   "August", "September", "October", "November", "December"};
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /* SAME ORDER AS THE NAMES */
	int month = 0;

	printf("Enter the month number (1-12): ");
	scanf("%d", &month);

	if (month < 1 || month > 12)
	{
		printf("Invalid month number\n");
	}
	else if (month == 2)
	{
		printf("February, 28 days (29 in a leap year)\n");
	}
	else
	{
		printf("%s, %d days\n", names[month - 1], days[month - 1]);
	}

	return 0;
}
