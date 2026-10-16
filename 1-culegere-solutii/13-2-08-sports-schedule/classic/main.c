/* CULEGERE XIII.2.8 - SPORTS SCHEDULE
 * A SCHOOL HAS AT MOST 7 CLASSES OF THE 6TH GRADE (VI A, VI B, VI C...). EVERY CLASS MUST MEET
 * EVERY OTHER CLASS EXACTLY ONCE, ONE MATCH A DAY, WITH NO MATCHES ON SUNDAYS, STARTING ON
 * WEDNESDAY, 1 JUNE 1988. PRINT THE SCHEDULE: DAY, DATE AND MATCH
 * EXAMPLE: 3 CLASSES -> WEDNESDAY 1 JUNE VI A - VI B, THURSDAY 2 JUNE VI A - VI C,
 *          FRIDAY 3 JUNE VI B - VI C
 * ASSUMPTION: THE NUMBER OF CLASSES (2 TO 7) IS READ; THE MATCHES GO IN THE ORDER A-B, A-C, ...,
 *             B-C, ... AS IN THE BOOK'S EXAMPLE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char day_name[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
		"Saturday", "Sunday"};
	int n = 0, i, j;
	int day = 1;      /* 1 JUNE 1988 ... */
	int week_day = 2; /* ... WAS A WEDNESDAY (0 = MONDAY, 6 = SUNDAY) */

	printf("Number of classes (2-7): ");
	scanf("%d", &n);

	/* EVERY PAIR OF CLASSES I < J PLAYS ONCE; 7 CLASSES GIVE 21 MATCHES, THE LAST ONE ON
	 * 24 JUNE, SO THE MONTH NEVER CHANGES */
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (week_day == 6)
			{
				day++; /* NO MATCH ON SUNDAY: GO ON TO MONDAY */
				week_day = 0;
			}
			printf("%-9s %2d June  ", day_name[week_day], day);
			printf("VI %c - VI %c\n", 'A' + i, 'A' + j);

			day++; /* THE NEXT MATCH IS ON THE NEXT DAY */
			week_day = (week_day + 1) % 7;
		}
	}

	return 0;
}
