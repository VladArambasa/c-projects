/* CULEGERE VI.5.4 - REMOVE THE ZEROS
 * COMPACT A VECTOR OF N INTEGERS: EVERY ELEMENT EQUAL TO 0 IS REMOVED AND ALL THE ELEMENTS TO
 * ITS RIGHT MOVE ONE POSITION LEFT, INTO ITS PLACE
 * V1: FOR EVERY 0, SHIFT THE REST OF THE VECTOR ONE PLACE LEFT, AS THE STATEMENT DESCRIBES
 * EXAMPLE: N=4, 9 0 0 5 -> 9 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	i = 0; /* CHECK EVERY POSITION; A 0 IS COVERED BY THE ELEMENTS TO ITS RIGHT */
	while (i < n)
	{
		if (a[i] == 0)
		{
			for (j = i; j < n - 1; j++) /* THE ELEMENTS TO ITS RIGHT MOVE ONE PLACE LEFT */
			{
				a[j] = a[j + 1];
			}
			n--; /* ONE ELEMENT LESS */
			/* POSITION I IS CHECKED AGAIN: ANOTHER ELEMENT HAS COME TO IT */
		}
		else
		{
			i++;
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
