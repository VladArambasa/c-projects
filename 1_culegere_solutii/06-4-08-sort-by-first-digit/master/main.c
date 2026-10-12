/* CULEGERE VI.4.8 - SORT BY THE FIRST DIGIT
 * N NUMBERS OF ONE OR TWO DIGITS ARE READ; PRINT THEM IN ASCENDING ORDER OF THEIR FIRST DIGIT
 * ASSUMPTION: NUMBERS WITH THE SAME FIRST DIGIT KEEP THE ORDER IN WHICH THEY WERE READ
 * (THE BOOK ACCEPTS BOTH ORDERS)
 * EXAMPLE: N=5, 34 2 5 62 25 -> 2 25 34 5 62 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

/* THE FIRST (LEFTMOST) DIGIT OF A NATURAL NUMBER */
int first_digit(int x)
{
	while (x >= 10) /* DROP THE LAST DIGIT UNTIL ONLY ONE DIGIT IS LEFT */
	{
		x = x / 10;
	}
	return x;
}

int main(void)
{
	int a[MAX];
	int n = 0, i, j, temp;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* BUBBLE SORT BY THE FIRST DIGIT. ONLY NEIGHBOURS WHOSE FIRST DIGITS ARE REALLY OUT OF ORDER
	 * ARE SWAPPED (>, NOT >=), SO NUMBERS WITH EQUAL FIRST DIGITS NEVER CHANGE THEIR ORDER */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (first_digit(a[j]) > first_digit(a[j + 1]))
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
