/* LIBRARY FINE: 2 PER DAY FOR DAYS 1-5, 4 PER DAY FOR DAYS 6-10, 6 PER DAY FOR DAYS 11-30
 * MORE THAN 30 DAYS LATE: THE MEMBERSHIP IS CANCELLED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int days = 0, fine;

	printf("Enter the number of late days: ");
	scanf("%d", &days);

	if (days <= 5)
	{
		fine = days * 2;
	}
	else if (days <= 10)
	{
		fine = 5 * 2 + (days - 5) * 4; /* FIRST 5 DAYS + THE DAYS AFTER THEM */
	}
	else if (days <= 30)
	{
		fine = 5 * 2 + 5 * 4 + (days - 10) * 6;
	}
	else
	{
		printf("Membership cancelled\n");
		return 0;
	}

	printf("Fine: %d\n", fine);

	return 0;
}
