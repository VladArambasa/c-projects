/* STANDARD STREAMS: STDIN, STDOUT AND STDERR ARE ALREADY OPEN WHEN MAIN STARTS
 * REDIRECT WITH < (STDIN FROM A FILE) AND > (STDOUT TO A FILE): STDERR STILL REACHES THE SCREEN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0;
	int count = 0;

	while (scanf("%d", &x) == 1) /* STOPS AT THE END OF THE INPUT OR AT A NON-NUMBER */
	{
		fprintf(stdout, "%d\n", x * x); /* RESULTS GO TO STDOUT (SAME AS PRINTF) */
		count++;
	}

	fprintf(stderr, "%d numbers squared\n", count); /* MESSAGES GO TO STDERR */
	return 0;
}
