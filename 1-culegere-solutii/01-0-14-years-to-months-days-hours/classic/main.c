/* CULEGERE I.14 - YEARS TO MONTHS, DAYS AND HOURS
 * READ A NUMBER OF YEARS AND PRINT THE MATCHING NUMBER OF MONTHS, DAYS AND HOURS
 * (A YEAR HAS 365 DAYS)
 * EXAMPLE: 2 -> 24 MONTHS  730 DAYS  17520 HOURS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int years = 0, months, days, hours;

	printf("Years: ");
	scanf("%d", &years);

	months = years * 12; /* 12 MONTHS IN A YEAR */
	days = years * 365; /* 365 DAYS IN A YEAR */
	hours = days * 24; /* 24 HOURS IN A DAY */

	printf("%d months  %d days  %d hours\n", months, days, hours);

	return 0;
}
