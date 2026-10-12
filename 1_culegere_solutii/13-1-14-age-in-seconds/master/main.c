/* CULEGERE XIII.1.14 - AGE FROM SECONDS
 * GIGEL GIVES HIS AGE IN SECONDS: N (N <= 2000000000); PRINT HOW MANY YEARS, MONTHS AND DAYS OLD HE
 * IS (THE HOURS AND MINUTES LEFT OVER DO NOT MATTER); TODAY IS THE LAST DAY OF SCHOOL, 15 JUNE 2002
 * LEAP YEARS (366 DAYS) ARE DIVISIBLE BY 4 BUT NOT BY 100, OR DIVISIBLE BY 400
 * EXAMPLE: N=69206400 -> GIGEL IS 2 YEARS, 2 MONTHS AND 10 DAYS OLD
 *   (69206400 SECONDS = 801 DAYS, SO HE WAS BORN ON 5 APRIL 2000)
 * ASSUMPTION: WHOLE YEARS, THEN WHOLE MONTHS, ARE COUNTED BACK FROM 15 JUNE 2002; WHAT IS LEFT
 *   ARE THE DAYS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* 1 IF THE YEAR HAS 366 DAYS, 0 OTHERWISE */
int is_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	return 0;
}

/* HOW MANY DAYS A MONTH HAS (1 = JANUARY, ..., 12 = DECEMBER) */
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
	int seconds = 0, days, years = 0, months = 0, year = 2002, month = 6, stop = 0;

	printf("N = ");
	scanf("%d", &seconds);

	days = seconds / 86400; /* 24 * 60 * 60 SECONDS IN A DAY; WHAT IS LEFT OVER IS DROPPED */

	/* WHOLE YEARS: FROM 15 JUNE OF THE YEAR BEFORE TO 15 JUNE OF THIS YEAR THERE ARE 366 DAYS
	 * IF THIS YEAR IS LEAP (ITS 29 FEBRUARY LIES IN BETWEEN), OTHERWISE 365 */
	while (days >= 365 + is_leap(year))
	{
		days = days - (365 + is_leap(year));
		years++;
		year--;
	}

	/* WHOLE MONTHS: FROM THE 15TH OF THE MONTH BEFORE TO THE 15TH OF THIS MONTH
	 * THERE ARE AS MANY DAYS AS THE MONTH BEFORE HAS */
	while (stop == 0)
	{
		month--;
		if (month == 0) /* BEFORE JANUARY COMES DECEMBER OF THE YEAR BEFORE */
		{
			month = 12;
			year--;
		}
		if (days >= days_in_month(month, year))
		{
			days = days - days_in_month(month, year);
			months++;
		}
		else
		{
			stop = 1;
		}
	}

	printf("Gigel is %d years, %d months and %d days old.\n", years, months, days);

	return 0;
}
