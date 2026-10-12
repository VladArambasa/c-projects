/* CULEGERE VII.4.4 - STUDENTS WHO REPEAT THE YEAR
 * THE AVERAGES OF M STUDENTS AT N SUBJECTS ARE READ; CHECK IF THE CLASS HAS STUDENTS WHO
 * REPEAT THE YEAR (AT LEAST THREE FAILED SUBJECTS) AND, IF SO, PRINT HOW MANY THERE ARE
 * EXAMPLE: M=3 N=4, 4.5 3 4 7 / 8 9 10 7 / 4 4 6 7 -> YES, 1 STUDENT
 * ASSUMPTION: A SUBJECT IS FAILED WHEN ITS AVERAGE IS BELOW 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 STUDENTS AND 50 SUBJECTS */

int main(void)
{
	double average[MAX][MAX] = {0};
	int m = 0, n = 0, i, j, failed, repeating;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Averages of student %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%lf", &average[i][j]);
		}
	}

	repeating = 0;
	for (i = 0; i < m; i++)
	{
		/* COUNT THE FAILED SUBJECTS ON THE ROW OF THIS STUDENT */
		failed = 0;
		for (j = 0; j < n; j++)
		{
			if (average[i][j] < 5)
			{
				failed++;
			}
		}
		if (failed >= 3)
		{
			repeating++;
		}
	}

	if (repeating > 0)
	{
		printf("Yes, students who repeat the year: %d\n", repeating);
	}
	else
	{
		printf("No student repeats the year\n");
	}

	return 0;
}
