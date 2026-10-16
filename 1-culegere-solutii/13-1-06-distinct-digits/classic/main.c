/* CULEGERE XIII.1.6 - DISTINCT DIGITS
 * N NATURAL NUMBERS SMALLER THAN 32000 (N < 30):
 * A) PRINT THE FIRST NUMBER THAT HAS THE MOST DISTINCT DIGITS
 * B) PRINT THE LONGEST RUN OF NEIGHBOURING NUMBERS THAT ALL HAVE THE SAME NUMBER OF DISTINCT DIGITS
 * EXAMPLE: 865 15 144 231 1591 1998 6235 14 4201 -> A) 6235  B) 231 1591 1998
 * ASSUMPTION: FOR TWO RUNS OF THE SAME LENGTH, THE FIRST ONE IS PRINTED */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 30

/* HOW MANY DIFFERENT DIGITS X HAS: 1591 -> 3 */
int distinct_digits(int x)
{
	int seen[10] = {0}; /* SEEN[D] = 1 WHEN DIGIT D WAS ALREADY MET */
	int count = 0;

	do
	{
		if (seen[x % 10] == 0)
		{
			seen[x % 10] = 1;
			count++;
		}
		x = x / 10;
	} while (x > 0);
	return count;
}

int main(void)
{
	int a[MAX], d[MAX]; /* D[I] = THE NUMBER OF DISTINCT DIGITS OF A[I] */
	int n = 0, i, best, start, length, best_start, best_length;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		d[i] = distinct_digits(a[i]);
	}

	best = 0; /* A) ONLY A STRICTLY BIGGER COUNT REPLACES IT, SO THE FIRST ONE STAYS */
	for (i = 1; i < n; i++)
	{
		if (d[i] > d[best])
		{
			best = i;
		}
	}
	printf("a) %d\n", a[best]);

	/* B) A RUN GROWS WHILE THE COUNT STAYS THE SAME AS FOR THE NUMBER BEFORE */
	start = 0;
	length = 1;
	best_start = 0;
	best_length = 1;
	for (i = 1; i < n; i++)
	{
		if (d[i] == d[i - 1])
		{
			length++;
		}
		else /* A NEW RUN STARTS HERE */
		{
			start = i;
			length = 1;
		}
		if (length > best_length)
		{
			best_length = length;
			best_start = start;
		}
	}
	printf("b)");
	for (i = best_start; i < best_start + best_length; i++)
	{
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
