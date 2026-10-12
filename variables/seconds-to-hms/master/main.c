/* CONVERT SECONDS TO HOURS:MINUTES:SECONDS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int total = 0, hours, minutes, seconds;

	printf("Enter the number of seconds: ");
	scanf("%d", &total);

	hours = total / 3600;           /* 3600 SECONDS IN AN HOUR */
	minutes = (total % 3600) / 60;  /* WHAT IS LEFT, IN MINUTES */
	seconds = total % 60;

	printf("%d:%02d:%02d\n", hours, minutes, seconds); /* 02 PADS WITH A ZERO */

	return 0;
}
