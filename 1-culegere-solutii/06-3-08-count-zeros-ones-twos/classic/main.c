/* CULEGERE VI.3.8 - ZEROS, ONES AND TWOS
 * N NUMBERS EQUAL TO 0, 1 OR 2 ARE READ. PRINT THE POSITION OF THE FIRST 0, HOW MANY TIMES EACH
 * DIGIT APPEARS AND WHICH DIGIT IS USED THE LEAST
 * EXAMPLE: N=7, 1 1 0 2 1 0 1 -> POSITION OF THE FIRST ZERO: 3 / DIGIT 0 APPEARS 2 TIMES /
 *          DIGIT 1 APPEARS 4 TIMES / DIGIT 2 APPEARS 1 TIME / LEAST USED DIGIT: 2
 * ASSUMPTION: IF SEVERAL DIGITS ARE USED EQUALLY LITTLE, THE SMALLEST OF THEM IS PRINTED;
 * WITHOUT ANY 0 A MESSAGE IS PRINTED INSTEAD OF THE POSITION */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int count[3] = {0}; /* COUNT[D] = HOW MANY TIMES THE DIGIT D APPEARS */
	int n = 0, i, d, least;
	int first_zero = 0; /* 0 = NO ZERO FOUND YET */

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		count[a[i]]++; /* THE VALUE ITSELF SHOWS WHICH COUNTER GROWS */
		if (a[i] == 0 && first_zero == 0)
		{
			first_zero = i + 1; /* POSITIONS ARE COUNTED FROM 1 */
		}
	}

	if (first_zero > 0)
	{
		printf("Position of the first zero: %d\n", first_zero);
	}
	else
	{
		printf("There is no zero\n");
	}

	for (d = 0; d <= 2; d++)
	{
		printf("Digit %d appears %d %s\n", d, count[d],
		       (count[d] == 1) ? "time" : "times");
	}

	least = 0; /* THE DIGIT WITH THE SMALLEST COUNTER; START WITH 0 */
	for (d = 1; d <= 2; d++)
	{
		if (count[d] < count[least])
		{
			least = d;
		}
	}
	printf("Least used digit: %d\n", least);

	return 0;
}
