/* SWITCH: WITHOUT BREAK, EXECUTION FALLS THROUGH INTO THE NEXT CASE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int day = 0;

	printf("Enter a day number (1-7): ");
	scanf("%d", &day);

	switch (day)
	{
	case 6:
	case 7: /* TWO CASES SHARE THE SAME CODE */
		printf("Weekend!\n");
		break; /* LEAVE THE SWITCH */
	default: /* EVERY OTHER VALUE */
		printf("Looking forward to the weekend\n");
	}

	printf("Countdown: ");
	switch (day) /* NO BREAKS: EVERY CASE AFTER THE MATCHING ONE RUNS TOO */
	{
	case 3:
		printf("3 ");
		/* FALL THROUGH */
	case 2:
		printf("2 ");
		/* FALL THROUGH */
	case 1:
		printf("1 ");
	}
	printf("go!\n");

	return 0;
}
