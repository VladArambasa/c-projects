/* CULEGERE VI.5.5 - MOVE A VALUE TO THE END
 * N NUMBERS AND A VALUE V ARE READ; MOVE ALL THE ELEMENTS EQUAL TO V TO THE END OF THE SEQUENCE
 * (THE OTHER ELEMENTS KEEP THEIR ORDER, AS IN THE EXAMPLE)
 * V1: FOR EVERY V, SHIFT THE ELEMENTS AFTER IT ONE PLACE LEFT AND PUT V ON THE LAST PLACE
 * EXAMPLE: N=4, V=5, 5 6 5 3 -> 6 3 5 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, v = 0, i, j, end;

	printf("n = ");
	scanf("%d", &n);
	printf("v = ");
	scanf("%d", &v);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	end = n; /* FROM POSITION END ON, THE VECTOR HOLDS ONLY VALUES V THAT WERE ALREADY MOVED */
	i = 0;
	while (i < end)
	{
		if (a[i] == v)
		{
			for (j = i; j < n - 1; j++) /* THE ELEMENTS AFTER IT MOVE ONE PLACE LEFT */
			{
				a[j] = a[j + 1];
			}
			a[n - 1] = v; /* V GOES ON THE LAST PLACE */
			end--;        /* ONE ELEMENT LESS TO CHECK */
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
