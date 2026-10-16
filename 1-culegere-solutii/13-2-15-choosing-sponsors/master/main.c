/* CULEGERE XIII.2.15 - CHOOSING SPONSORS
 * THE CONTEST NEEDS THE SUM S. N PERSONS (N < 1000) EACH OFFER A SUM (IN MILLIONS). CHOOSE AS
 * FEW PERSONS AS POSSIBLE SO THAT THEIR OFFERS TOGETHER COVER S, AND PRINT THE CHOSEN OFFERS
 * EXAMPLE: N=8 S=30, 2.5 3 2 5 15 7 4 1 -> 15 7 5 3
 *          N=7 S=37, 5.5 4.5 2 17 2 5.5 10 -> 17 10 5.5 4.5
 * ASSUMPTION: AS IN THE EXAMPLES, THE BIGGEST OFFERS ARE TAKEN WHILE NO OFFER LEFT CAN COVER WHAT
 *             IS STILL MISSING, THEN THE SMALLEST OFFER THAT COVERS IT; IF ALL THE OFFERS
 *             TOGETHER ARE NOT ENOUGH, "NOT POSSIBLE" IS PRINTED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 1000

/* SORTS THE OFFERS FROM THE BIGGEST TO THE SMALLEST (SELECTION SORT) */
void sort_descending(double x[], int n)
{
	int i, j, big;
	double aux;

	for (i = 0; i < n - 1; i++)
	{
		big = i; /* THE BIGGEST OF X[I] ... X[N - 1] GOES ON POSITION I */
		for (j = i + 1; j < n; j++)
		{
			if (x[j] > x[big])
			{
				big = j;
			}
		}
		aux = x[i];
		x[i] = x[big];
		x[big] = aux;
	}
}

int main(void)
{
	double offer[MAX] = {0};
	double s = 0, missing;
	int n = 0, i, j, last;

	printf("N = ");
	scanf("%d", &n);
	printf("S = ");
	scanf("%lf", &s);
	printf("The %d offers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &offer[i]);
	}

	sort_descending(offer, n);

	/* FEWEST PERSONS: TAKE THE BIGGEST OFFERS WHILE EVEN THE BIGGEST ONE LEFT IS NOT ENOUGH */
	missing = s;
	i = 0;
	while (i < n && offer[i] < missing)
	{
		missing = missing - offer[i];
		i++;
	}

	if (i == n)
	{
		printf("Not possible\n"); /* ALL THE OFFERS TOGETHER DO NOT COVER S */
	}
	else
	{
		/* OFFER[I] COVERS WHAT IS MISSING; SMALLER OFFERS AFTER IT MAY COVER IT TOO,
		 * SO TAKE THE LAST (SMALLEST) ONE THAT STILL DOES */
		last = i;
		while (last + 1 < n && offer[last + 1] >= missing)
		{
			last++;
		}

		printf("Chosen offers:");
		for (j = 0; j < i; j++)
		{
			printf(" %g", offer[j]);
		}
		printf(" %g\n", offer[last]);
	}

	return 0;
}
