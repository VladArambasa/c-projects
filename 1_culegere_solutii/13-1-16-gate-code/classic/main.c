/* CULEGERE XIII.1.16 - THE GATE CODE
 * THE GATEKEEPER CALLS S DIGITS (3 <= S <= 10); COPA TYPES EACH ONE INTO THE NEXT EMPTY BOX, AND AT
 * THE SAME TIME EVERY BOX FILLED BEFORE GOES UP BY 1 (AFTER 9 COMES 0); THE SECOND CODE N IS THE
 * SMALLEST NUMBER MADE OF AS MANY DIGITS OF THE FIRST CODE AS POSSIBLE, WITH NO DIGIT REPEATED
 * EXAMPLE: S=10, DIGITS 1 0 7 9 7 3 6 9 4 6 -> FIRST CODE 0845279156, N = 102456789 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 10 /* S <= 10 */

int main(void)
{
	int called[MAX + 1]; /* THE DIGITS CALLED BY THE GATEKEEPER */
	int box[MAX + 1];    /* THE FIRST CODE */
	int seen[10];        /* SEEN[D] = 1 WHEN DIGIT D IS IN THE FIRST CODE */
	int s = 0, i, d, first = 0;

	printf("s = ");
	scanf("%d", &s);
	printf("The %d digits called: ", s);
	for (i = 1; i <= s; i++)
	{
		scanf("%d", &called[i]);
	}

	/* THE DIGIT OF BOX I GOES UP BY 1 FOR EACH OF THE S - I DIGITS TYPED AFTER IT */
	for (i = 1; i <= s; i++)
	{
		box[i] = (called[i] + s - i) % 10; /* % 10: AFTER 9 COMES 0 */
	}
	printf("First code: ");
	for (i = 1; i <= s; i++)
	{
		printf("%d", box[i]);
	}
	printf("\n");

	for (d = 0; d <= 9; d++)
	{
		seen[d] = 0;
	}
	for (i = 1; i <= s; i++)
	{
		seen[box[i]] = 1;
	}

	/* THE SMALLEST NUMBER WITH ALL THESE DIGITS: THE SMALLEST NON-ZERO DIGIT FIRST
	 * (A NUMBER DOES NOT START WITH 0), THEN ALL THE OTHERS IN INCREASING ORDER, 0 INCLUDED */
	for (d = 1; d <= 9 && first == 0; d++)
	{
		if (seen[d] == 1)
		{
			first = d;
		}
	}
	printf("N = ");
	if (first == 0) /* THE FIRST CODE HAS ONLY ZEROS */
	{
		printf("0");
	}
	else
	{
		printf("%d", first);
		for (d = 0; d <= 9; d++)
		{
			if (seen[d] == 1 && d != first)
			{
				printf("%d", d);
			}
		}
	}
	printf("\n");

	return 0;
}
