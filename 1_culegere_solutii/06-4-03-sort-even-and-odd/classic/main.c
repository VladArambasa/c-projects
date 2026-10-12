/* CULEGERE VI.4.3 - EVEN ASCENDING, ODD DESCENDING
 * N NATURAL NUMBERS ARE READ; PRINT THEM WITH THE EVEN NUMBERS IN ASCENDING ORDER AND THE ODD
 * NUMBERS IN DESCENDING ORDER
 * ASSUMPTION: AS IN THE BOOK'S EXAMPLE, EVERY PLACE KEEPS A NUMBER OF THE SAME PARITY: THE EVEN
 * NUMBERS ARE SORTED AMONG THE PLACES THAT HELD EVEN NUMBERS, THE ODD ONES AMONG THE OTHER PLACES
 * NOTE: THE BOOK'S EXAMPLE SAYS 2 1 3 5 4 5 8; THE CORRECT RESULT IS 2 5 5 3 4 1 8
 * (THE BOOK PUT THE ODD NUMBERS IN ASCENDING ORDER)
 * EXAMPLE: N=7, 2 5 3 1 8 5 4 -> 2 5 5 3 4 1 8 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

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

	/* SORT BY EXCHANGE: COMPARE EVERY ELEMENT WITH ALL THE ELEMENTS AFTER IT. ONLY TWO NUMBERS
	 * OF THE SAME PARITY ARE EVER SWAPPED, SO EVERY PLACE KEEPS A NUMBER OF THE SAME PARITY */
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j])
			{
				/* TWO EVEN NUMBERS IN THE WRONG ORDER: THE SMALLER ONE MUST COME FIRST */
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else if (a[i] % 2 == 1 && a[j] % 2 == 1 && a[i] < a[j])
			{
				/* TWO ODD NUMBERS IN THE WRONG ORDER: THE LARGER ONE MUST COME FIRST */
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
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
