/* CULEGERE VI.3.6 - THE DIET (V2)
 * N PEOPLE WITH THE WEIGHTS G(I) FOLLOW A K-DAY DIET. THE IDEAL WEIGHT IS FROM A TO B KG. EVERY
 * DAY THOSE UNDER THE IDEAL WEIGHT GAIN 1 KG, THOSE OVER IT LOSE 1 KG AND THE OTHERS KEEP THEIR
 * WEIGHT. PRINT HOW MANY PEOPLE HAVE THE IDEAL WEIGHT A) AT THE START, B) AFTER THE K DAYS
 * EXAMPLE: N=10 K=7 A=40 B=50, 38 41 48 50 54 58 60 42 32 55 -> A) 4 PEOPLE  B) 7 PEOPLE
 * ASSUMPTION: THE BOOK'S EXAMPLE SAYS N=10 BUT LISTS ONLY 9 WEIGHTS, WHICH WOULD GIVE 6 PEOPLE
 * AFTER THE DIET; THE EXAMPLE ABOVE ADDS A 10TH WEIGHT, 55, SO THE BOOK'S RESULTS 4 AND 7 HOLD
 * ASSUMPTION: A PERSON STOPS CHANGING AS SOON AS THE WEIGHT IS BETWEEN A AND B
 * IMPROVEMENT: NO SIMULATION; AFTER K DAYS A WEIGHT G IS IDEAL EXACTLY WHEN A-K <= G <= B+K */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int g[MAX] = {0};
	int n = 0, k = 0, a = 0, b = 0, i;
	int start = 0, end = 0;

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

	for (i = 0; i < n; i++) /* ONE CHECK PER PERSON, WHATEVER THE NUMBER OF DAYS */
	{
		if (g[i] >= a && g[i] <= b) /* IDEAL FROM THE START */
		{
			start++;
		}
		/* AT MOST K KG AWAY FROM THE IDEAL WEIGHT: K DAYS ARE ENOUGH TO GET THERE */
		if (g[i] >= a - k && g[i] <= b + k)
		{
			end++;
		}
	}

	printf("a) %d %s\n", start, (start == 1) ? "person" : "people");
	printf("b) %d %s\n", end, (end == 1) ? "person" : "people");

	return 0;
}
