/* CULEGERE VI.6.8 - SAME ELEMENTS
 * CHECK IF TWO VECTORS OF THE SAME LENGTH N HAVE THE SAME ELEMENTS, BY SORTING BOTH VECTORS
 * FIRST: THEN THEY MUST BE EQUAL POSITION BY POSITION
 * ASSUMPTION: A REPEATED VALUE MUST APPEAR THE SAME NUMBER OF TIMES IN BOTH VECTORS
 * EXAMPLES: N=3, 4 2 6 AND 6 2 4 -> YES; N=2, 4 2 AND 3 4 -> NO */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 ELEMENTS IN EACH VECTOR */

/* BUBBLE SORT OF THE FIRST N ELEMENTS OF V, IN ASCENDING ORDER */
void sort_vector(int v[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, i, ok;

	printf("n = ");
	scanf("%d", &n);
	printf("First vector: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Second vector: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}

	sort_vector(a, n); /* THE SAME FUNCTION SORTS BOTH VECTORS */
	sort_vector(b, n);

	ok = 1; /* THE SAME ELEMENTS, UNTIL A POSITION SHOWS A DIFFERENCE */
	for (i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			ok = 0;
		}
	}

	if (ok == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
