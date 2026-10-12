/* CULEGERE XIII.2.3 - COLORED CUBES
 * N CUBES (N < 50) STAND IN A ROW; THEIR COLORS ARE NUMBERS FROM 1 TO 10. PRINT:
 * A. HOW MANY COLORS THERE ARE; B. THE COLOR USED FOR THE MOST CUBES; C. THE CUBE TO TAKE OUT SO
 * THAT THE CUBES LEFT HAVE THE LONGEST POSSIBLE RUN OF NEIGHBOURS WITH THE SAME COLOR.
 * WHEN THERE ARE MORE SOLUTIONS, ALL OF THEM ARE PRINTED
 * EXAMPLE: 5 2 5 2 2 3 3 2 3 5 3 3 3 2 2 -> A. 3  B. 2 3  C. POSITION 10 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50
#define COLORS 10

/* THE LONGEST RUN OF NEIGHBOURS WITH THE SAME COLOR WHEN THE CUBE ON POSITION SKIP IS TAKEN OUT */
int longest_run_without(int cube[], int n, int skip)
{
	int i, prev = 0, run = 0, best = 0;

	for (i = 1; i <= n; i++)
	{
		if (i != skip)
		{
			if (cube[i] == prev)
			{
				run++; /* SAME COLOR AS THE CUBE BEFORE: THE RUN GOES ON */
			}
			else
			{
				run = 1; /* A NEW RUN (THERE IS NO COLOR 0, SO THE FIRST CUBE STARTS ONE) */
			}
			prev = cube[i];
			if (run > best)
			{
				best = run;
			}
		}
	}
	return best;
}

int main(void)
{
	int cube[MAX + 1] = {0};
	int count[COLORS + 1] = {0}; /* COUNT[C] = HOW MANY CUBES HAVE COLOR C */
	int run[MAX + 1] = {0};      /* RUN[I] = THE LONGEST RUN WHEN CUBE I IS TAKEN OUT */
	int n = 0, i, colors = 0, most = 0, best = 0, solutions = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d colors: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &cube[i]);
		count[cube[i]]++;
	}

	/* A. THE COLORS THAT APPEAR; ALSO THE BIGGEST NUMBER OF CUBES OF ONE COLOR */
	for (i = 1; i <= COLORS; i++)
	{
		if (count[i] > 0)
		{
			colors++;
		}
		if (count[i] > most)
		{
			most = count[i];
		}
	}
	printf("a. %d\n", colors);

	/* B. EVERY COLOR THAT HAS THIS BIGGEST NUMBER OF CUBES */
	printf("b.");
	for (i = 1; i <= COLORS; i++)
	{
		if (count[i] == most)
		{
			printf(" %d", i);
		}
	}
	printf("\n");

	/* C. TAKE OUT EACH CUBE IN TURN, MEASURE THE LONGEST RUN LEFT AND COUNT THE BEST CHOICES */
	for (i = 1; i <= n; i++)
	{
		run[i] = longest_run_without(cube, n, i);
		if (run[i] > best)
		{
			best = run[i];
			solutions = 1;
		}
		else if (run[i] == best)
		{
			solutions++;
		}
	}
	if (solutions == 1)
	{
		printf("c. Position");
	}
	else
	{
		printf("c. Positions");
	}
	for (i = 1; i <= n; i++)
	{
		if (run[i] == best)
		{
			printf(" %d", i);
		}
	}
	printf("\n");

	return 0;
}
