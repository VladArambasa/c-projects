/* STDLIB.H: TEXT TO NUMBER, ABSOLUTE VALUE, RANDOM NUMBERS AND SORTING */
#include <stdio.h>  /* PRINTF */
#include <stdlib.h> /* ATOI, ATOF, ABS, RAND, SRAND, QSORT */

int compare(const void *a, const void *b) /* QSORT ASKS: WHICH OF THE TWO COMES FIRST? */
{
	int x = *(int *)a;
	int y = *(int *)b;

	return x - y; /* NEGATIVE: X FIRST, POSITIVE: Y FIRST */
}

int main(void)
{
	int t[6] = {42, 7, 19, 3, 25, 11};
	int i;

	printf("atoi(\"123\") + 1 = %d\n", atoi("123") + 1); /* TEXT TO INT */
	printf("atof(\"2.5\") * 2 = %.1f\n", atof("2.5") * 2); /* TEXT TO DOUBLE */
	printf("abs(-7) = %d\n", abs(-7));

	srand(2026); /* THE SAME SEED GIVES THE SAME SEQUENCE */
	printf("Three dice rolls:");
	for (i = 0; i < 3; i++)
	{
		printf(" %d", rand() % 6 + 1); /* 1 TO 6 */
	}
	printf("\n");

	qsort(t, 6, sizeof(int), compare); /* ARRAY, COUNT, ELEMENT SIZE, COMPARISON FUNCTION */
	printf("Sorted:");
	for (i = 0; i < 6; i++)
	{
		printf(" %d", t[i]);
	}
	printf("\n");

	return 0;
}
