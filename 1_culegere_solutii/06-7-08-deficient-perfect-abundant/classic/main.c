/* CULEGERE VI.7.8 - DEFICIENT, PERFECT, ABUNDANT
 * A NUMBER IS DEFICIENT IF IT IS LARGER THAN THE SUM OF ITS DIVISORS SMALLER THAN ITSELF, PERFECT
 * IF IT IS EQUAL TO THAT SUM AND ABUNDANT IF IT IS SMALLER. USING COUNTING AND AN AUXILIARY
 * VECTOR, GROUP N NUMBERS: FIRST THE DEFICIENT ONES, THEN THE PERFECT ONES, THEN THE ABUNDANT ONES
 * ASSUMPTION: THE NUMBERS ARE NATURAL, AT LEAST 1; INSIDE A GROUP THE NUMBERS KEEP THE INPUT
 * ORDER (AS IN THE EXAMPLE)
 * EXAMPLE: N=5, 6 12 3 4 10 -> 3 4 10 6 12 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */
#define DEFICIENT 0
#define PERFECT 1
#define ABUNDANT 2

/* THE KIND OF X: COMPARE X WITH THE SUM OF ITS DIVISORS SMALLER THAN X */
int kind_of(int x)
{
	int d, sum = 0;

	for (d = 1; d < x; d++)
	{
		if (x % d == 0)
		{
			sum = sum + d;
		}
	}
	if (x > sum)
	{
		return DEFICIENT;
	}
	if (x == sum)
	{
		return PERFECT;
	}
	return ABUNDANT;
}

int main(void)
{
	int a[MAX], b[MAX], kind[MAX];
	int count[3] = {0}; /* HOW MANY NUMBERS OF EACH KIND */
	int place[3];       /* THE NEXT FREE PLACE IN B FOR EACH KIND */
	int n = 0, i, k;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* 1. FIND THE KIND OF EVERY NUMBER AND COUNT THE NUMBERS OF EACH KIND */
	for (i = 0; i < n; i++)
	{
		kind[i] = kind_of(a[i]);
		count[kind[i]]++;
	}

	/* 2. THE COUNTS TELL WHERE EVERY GROUP STARTS IN B: THE DEFICIENT NUMBERS AT PLACE 0,
	 * THE PERFECT ONES RIGHT AFTER THEM, THE ABUNDANT ONES AFTER THE PERFECT ONES */
	place[DEFICIENT] = 0;
	place[PERFECT] = count[DEFICIENT];
	place[ABUNDANT] = count[DEFICIENT] + count[PERFECT];

	/* 3. COPY EVERY NUMBER INTO B, ON THE NEXT FREE PLACE OF ITS GROUP */
	for (i = 0; i < n; i++)
	{
		k = kind[i];
		b[place[k]] = a[i];
		place[k]++;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}
