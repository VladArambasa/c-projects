/* CULEGERE VII.5.2 - TABLE WITH ALL PRODUCTS EQUAL TO -1
 * A NATURAL NUMBER N (0 < N < 26) IS READ; BUILD AN N X N TABLE WITH ELEMENTS FROM {-1, 1} SO
 * THAT THE PRODUCT OF EVERY ROW AND THE PRODUCT OF EVERY COLUMN IS -1; PRINT ONE SUCH TABLE
 * EXAMPLE: N=4 -> -1 1 1 1 / 1 -1 1 1 / 1 1 -1 1 / 1 1 1 -1 (ANY CORRECT TABLE IS GOOD)
 * (CNI SATU MARE 2002, GRADE 6) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 25 /* N IS AT MOST 25 */

int main(void)
{
	int a[MAX][MAX];
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);

	/* -1 ON THE MAIN DIAGONAL AND 1 EVERYWHERE ELSE: EVERY ROW AND EVERY COLUMN HOLDS
	 * EXACTLY ONE -1, SO EVERY PRODUCT IS -1 */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				a[i][j] = -1;
			}
			else
			{
				a[i][j] = 1;
			}
		}
	}

	/* %3D KEEPS THE COLUMNS ALIGNED */
	printf("The table:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
