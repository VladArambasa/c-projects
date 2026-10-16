/* CULEGERE XIII.2.30 - ROCKET RETURN DATE
 * THE YEAR, DAY, MONTH AND HOUR OF THE DEPARTURE OF A ROCKET AND THE LENGTH OF ITS FLIGHT IN
 * MINUTES (AT MOST ONE YEAR) ARE READ; PRINT THE YEAR, DAY, MONTH AND HOUR OF ITS RETURN TO EARTH
 * EXAMPLE: YEAR 2023, DAY 31, MONTH 12, HOUR 22 30, 120 MINUTES -> YEAR 2024, DAY 1, MONTH 1, 00:30
 * ASSUMPTION: THE HOUR IS GIVEN AS HOURS AND MINUTES; LEAP YEARS ARE COUNTED (FEBRUARY 29) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* 1 IF THE YEAR IS A LEAP YEAR: DIVISIBLE BY 4 BUT NOT BY 100, OR DIVISIBLE BY 400 */
int is_leap(int year)
{
	if (year % 400 == 0)
	{
		return 1;
	}
	if (year % 100 == 0)
	{
		return 0;
	}
	if (year % 4 == 0)
	{
		return 1;
	}
	return 0;
}

/* HOW MANY DAYS THE MONTH HAS IN THAT YEAR */
int days_in_month(int month, int year)
{
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && is_leap(year) == 1)
	{
		return 29;
	}
	return days[month];
}

int main(void)
{
	int year = 0, day = 0, month = 0, hour = 0, minute = 0, flight = 0, days;

	printf("Year: ");
	scanf("%d", &year);
	printf("Day: ");
	scanf("%d", &day);
	printf("Month: ");
	scanf("%d", &month);
	printf("Hour and minute: ");
	scanf("%d %d", &hour, &minute);
	printf("Flight time in minutes: ");
	scanf("%d", &flight);

	/* ADD THE MINUTES; EVERY 60 MINUTES MAKE ONE HOUR AND EVERY 24 HOURS MAKE ONE DAY */
	minute = minute + flight;
	hour = hour + minute / 60;
	minute = minute % 60;
	days = hour / 24;
	hour = hour % 24;

	/* ADD THE DAYS ONE BY ONE, MOVING TO THE NEXT MONTH AND THE NEXT YEAR WHEN NEEDED */
	while (days > 0)
	{
		day++;
		if (day > days_in_month(month, year))
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
		days--;
	}

	printf("Return: year %d, day %d, month %d, ", year, day, month);
	printf("hour %02d:%02d\n", hour, minute); /* 2 DIGITS EACH, LIKE 00:30 */
	return 0;
}
