/* CULEGERE XIII.2.4 - BOYS IN THE ROWS
 * PUPILS STAND IN ROWS: THE LAST ROW HAS N PUPILS (1 <= N <= 20) AND EVERY ROW IN FRONT OF IT HAS
 * ONE PUPIL LESS. ON POSITION I STANDS A GIRL (0) IF THE PUPILS ON POSITIONS I AND I+1 OF THE ROW
 * BEHIND ARE OF THE SAME SEX, AND A BOY (1) OTHERWISE. GIVEN THE LAST ROW, PRINT HOW MANY BOYS
 * THERE ARE IN THE WHOLE CLASS
 * EXAMPLE: N=5, LAST ROW 1 0 0 1 1 -> 8 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 20

int main(void)
{
	int row[MAX] = {0};
	int n = 0, len, i, boys = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The last row (0 = girl, 1 = boy): ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &row[i]);
	}

	/* COUNT THE BOYS OF A ROW, THEN BUILD THE ROW IN FRONT OF IT, WHICH IS ONE PUPIL SHORTER */
	for (len = n; len >= 1; len--)
	{
		for (i = 0; i < len; i++)
		{
			boys = boys + row[i]; /* A BOY IS 1, A GIRL IS 0 */
		}

		/* THE SAME ARRAY IS REUSED: ROW[I + 1] IS STILL THE OLD ONE WHEN ROW[I] CHANGES */
		for (i = 0; i < len - 1; i++)
		{
			if (row[i] == row[i + 1])
			{
				row[i] = 0; /* SAME SEX BEHIND: A GIRL */
			}
			else
			{
				row[i] = 1; /* A BOY AND A GIRL BEHIND: A BOY */
			}
		}
	}

	printf("Number of boys: %d\n", boys);

	return 0;
}
