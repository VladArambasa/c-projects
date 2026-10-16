/* CULEGERE VI.5.1 - INSERT 0 IN FRONT
 * INSERT THE DIGIT 0 ON THE FIRST POSITION OF A GIVEN VECTOR, WITHOUT USING ANOTHER VECTOR
 * EXAMPLE: N=4, 5 3 7 8 -> 0 5 3 7 8 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX + 1]; /* ONE EXTRA PLACE FOR THE NEW ELEMENT */
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	/* MOVE EVERY ELEMENT ONE PLACE RIGHT, STARTING WITH THE LAST ONE:
	 * GOING BACKWARDS, NO ELEMENT IS OVERWRITTEN BEFORE IT HAS BEEN MOVED */
	for (i = n; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = 0; /* THE FIRST PLACE IS FREE NOW */
	n++;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
