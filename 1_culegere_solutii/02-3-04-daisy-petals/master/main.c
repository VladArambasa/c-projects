/* CULEGERE II.3.4 - DAISY PETALS
 * "HE LOVES ME A LITTLE, A LOT, PASSIONATELY, MADLY, NOT AT ALL, A LITTLE, ..."
 * PULLING OFF THE X PETALS OF A DAISY, PRINT HOW HE (SHE) LOVES ME
 * EXAMPLE: X=10 -> ... NOT AT ALL */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0, r;

	printf("x = ");
	scanf("%d", &x);

	r = x % 5; /* THE 5 ANSWERS REPEAT, SO ONLY THE REMAINDER BY 5 MATTERS */

	if (r == 1)
	{
		printf("... a little\n");
	}
	else if (r == 2)
	{
		printf("... a lot\n");
	}
	else if (r == 3)
	{
		printf("... passionately\n");
	}
	else if (r == 4)
	{
		printf("... madly\n");
	}
	else
	{
		printf("... not at all\n"); /* REMAINDER 0: THE 5TH ANSWER */
	}

	return 0;
}
