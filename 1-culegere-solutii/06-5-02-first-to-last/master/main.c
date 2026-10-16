/* CULEGERE VI.5.2 - FIRST ELEMENT TO THE END
 * N NUMBERS ARE READ; REARRANGE THEM SO THAT THE FIRST ONE ENDS UP ON THE LAST POSITION
 * (ALL THE OTHERS MOVE ONE PLACE LEFT)
 * EXAMPLE: N=3, 1 2 3 -> 2 3 1 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, i, first;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	first = a[0]; /* SAVE IT: ITS PLACE IS OVERWRITTEN BY THE NEXT ELEMENT */
	for (i = 0; i < n - 1; i++) /* EVERY OTHER ELEMENT MOVES ONE PLACE LEFT */
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = first; /* THE FIRST ELEMENT GOES ON THE LAST PLACE */

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
