/* CULEGERE VI.3.21 - INTERSECTION OF SETS OF CONSECUTIVE NUMBERS
 * N SETS ARE GIVEN, EACH MADE OF CONSECUTIVE NUMBERS, SO EVERY SET IS GIVEN BY ITS SMALLEST AND
 * ITS LARGEST ELEMENT. PRINT THE ELEMENTS OF THE INTERSECTION OF THE N SETS
 * (0 < N < 31, THE ELEMENTS ARE NATURAL NUMBERS SMALLER THAN 41)
 * EXAMPLE: N=3, 5 10 / 2 9 / 4 11 -> 5 6 7 8 9
 * ASSUMPTION: IF THE INTERSECTION IS EMPTY, THE PROGRAM PRINTS "EMPTY INTERSECTION"
 * IDEA: THE INTERSECTION STARTS AT THE LARGEST FIRST ELEMENT AND ENDS AT THE SMALLEST LAST ONE */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 30 /* AT MOST 30 SETS */

int main(void)
{
	int first[MAX] = {0}, last[MAX] = {0};
	int n = 0, i, low, high, x;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d pairs (first last), one per line:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &first[i], &last[i]);
	}

	low = first[0];
	high = last[0];
	for (i = 1; i < n; i++)
	{
		if (first[i] > low) /* NUMBERS BELOW FIRST[I] ARE MISSING FROM SET I */
		{
			low = first[i];
		}
		if (last[i] < high) /* NUMBERS ABOVE LAST[I] ARE MISSING FROM SET I */
		{
			high = last[i];
		}
	}

	if (low > high)
	{
		printf("Empty intersection\n");
	}
	else
	{
		for (x = low; x <= high; x++)
		{
			printf("%d ", x);
		}
		printf("\n");
	}

	return 0;
}
