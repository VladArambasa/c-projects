/* CULEGERE VI.2.1 - PRINT UNTIL THE FIRST ZERO
 * PRINT THE ELEMENTS OF A VECTOR UP TO THE FIRST ZERO VALUE. IF THERE IS NO 0, PRINT ALL THE
 * NUMBERS AND THE MESSAGE "NO ZERO ELEMENT"
 * EXAMPLE: 5 ELEMENTS, 3 6 8 0 2 -> 3 6 8
 * NOTE: THE BOOK'S EXAMPLE SAYS 5 ELEMENTS BUT LISTS 6 NUMBERS (3 6 8 0 2 3); SAME RESULT */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i;

	printf("Number of elements: ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	i = 0;
	while (i < n && a[i] != 0) /* STOP AT THE END OF THE VECTOR OR AT THE FIRST ZERO */
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");

	if (i == n) /* WE REACHED THE END, SO THERE WAS NO ZERO */
	{
		printf("No zero element\n");
	}

	return 0;
}
