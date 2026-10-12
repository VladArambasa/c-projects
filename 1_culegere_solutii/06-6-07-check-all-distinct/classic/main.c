/* CULEGERE VI.6.7 - IS IT A SET
 * CHECK IF N NUMBERS FORM A SET (ALL OF THEM ARE DIFFERENT) BY SORTING THEM FIRST:
 * AFTER SORTING, EQUAL NUMBERS ARE NEIGHBOURS
 * EXAMPLES: N=4, 4 6 2 6 -> NO; N=3, 3 5 2 -> YES */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, i, j, temp, ok;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* BUBBLE SORT IN ASCENDING ORDER */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	ok = 1; /* A SET, UNTIL TWO EQUAL NEIGHBOURS ARE FOUND */
	for (i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
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
