/* CULEGERE VI.6.5 - SUBSEQUENCE CHECK
 * A HAS N ELEMENTS AND B HAS M ELEMENTS (M < N). CHECK IF B IS A SUBSEQUENCE OF A: ITS ELEMENTS
 * APPEAR IN A IN THE SAME ORDER, BUT NOT NECESSARILY NEXT TO EACH OTHER
 * EXAMPLE: N=4, A: 1 2 3 4, M=2, B: 2 4 -> YES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 ELEMENTS */

int main(void)
{
	int a[MAX], b[MAX];
	int n = 0, m = 0, i, j;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d elements of a: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("m = ");
	scanf("%d", &m);
	printf("The %d elements of b: ", m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}

	/* WALK THROUGH A ONCE; B[J] IS THE ELEMENT OF B WE ARE LOOKING FOR. TAKING THE FIRST
	 * MATCH IS ALWAYS SAFE: IT LEAVES THE MOST ROOM FOR THE REST OF B */
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (j < m && a[i] == b[j]) /* B[J] FOUND: NOW LOOK FOR B[J + 1], FURTHER ON */
		{
			j++;
		}
	}

	if (j == m) /* ALL THE ELEMENTS OF B WERE FOUND, IN ORDER */
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
