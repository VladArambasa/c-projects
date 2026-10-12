/* CULEGERE VII.4.1 - SYMMETRIC MATRIX
 * AN N X N MATRIX IS READ; CHECK IF IT IS SYMMETRIC (THE ELEMENTS PLACED SYMMETRICALLY TO THE
 * MAIN DIAGONAL ARE EQUAL)
 * EXAMPLE: N=3, 3 4 5 / 4 1 7 / 5 7 0 -> YES */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int n = 0, i, j, symmetric;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* EACH ELEMENT UNDER THE MAIN DIAGONAL (J < I) IS COMPARED WITH ITS MIRROR A[J][I];
	 * THE ELEMENTS ABOVE THE DIAGONAL ARE THE MIRRORS, SO THEY NEED NO SECOND CHECK */
	symmetric = 1;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i][j] != a[j][i])
			{
				symmetric = 0;
			}
		}
	}

	if (symmetric == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
