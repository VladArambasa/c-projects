/* CULEGERE VI.3.6 - THE DIET (V1)
 * N PEOPLE WITH THE WEIGHTS G(I) FOLLOW A K-DAY DIET. THE IDEAL WEIGHT IS FROM A TO B KG. EVERY
 * DAY THOSE UNDER THE IDEAL WEIGHT GAIN 1 KG, THOSE OVER IT LOSE 1 KG AND THE OTHERS KEEP THEIR
 * WEIGHT. PRINT HOW MANY PEOPLE HAVE THE IDEAL WEIGHT A) AT THE START, B) AFTER THE K DAYS
 * EXAMPLE: N=10 K=7 A=40 B=50, 38 41 48 50 54 58 60 42 32 55 -> A) 4 PEOPLE  B) 7 PEOPLE
 * ASSUMPTION: THE BOOK'S EXAMPLE SAYS N=10 BUT LISTS ONLY 9 WEIGHTS, WHICH WOULD GIVE 6 PEOPLE
 * AFTER THE DIET; THE EXAMPLE ABOVE ADDS A 10TH WEIGHT, 55, SO THE BOOK'S RESULTS 4 AND 7 HOLD
 * ASSUMPTION: A PERSON STOPS CHANGING AS SOON AS THE WEIGHT IS BETWEEN A AND B
 * IDEA: SIMULATE THE DIET DAY BY DAY */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

/* HOW MANY OF THE N WEIGHTS ARE IDEAL, THAT IS BETWEEN A AND B */
int count_ideal(int g[], int n, int a, int b)
{
	int i, count = 0;

	for (i = 0; i < n; i++)
	{
		if (g[i] >= a && g[i] <= b)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	int g[MAX] = {0};
	int n = 0, k = 0, a = 0, b = 0, i, day;
	int ideal; /* HOW MANY PEOPLE HAVE THE IDEAL WEIGHT */

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("The %d weights: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &g[i]);
	}

	ideal = count_ideal(g, n, a, b);
	printf("a) %d %s\n", ideal, (ideal == 1) ? "person" : "people");

	for (day = 1; day <= k; day++) /* ONE DAY OF DIET FOR EVERYBODY */
	{
		for (i = 0; i < n; i++)
		{
			if (g[i] < a)
			{
				g[i]++; /* UNDER THE IDEAL WEIGHT: GAINS 1 KG */
			}
			else if (g[i] > b)
			{
				g[i]--; /* OVER THE IDEAL WEIGHT: LOSES 1 KG */
			}
		}
	}

	ideal = count_ideal(g, n, a, b);
	printf("b) %d %s\n", ideal, (ideal == 1) ? "person" : "people");

	return 0;
}
