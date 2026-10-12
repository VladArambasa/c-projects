/* CULEGERE VII.1.4 - SUM, PRODUCT AND INTEGER ELEMENTS
 * A MATRIX WITH M ROWS AND N COLUMNS HAS REAL ELEMENTS; PRINT THE SUM AND THE PRODUCT OF ALL
 * ITS ELEMENTS AND HOW MANY OF THEM ARE INTEGERS
 * EXAMPLE: M=2 N=3, 4 5 3 / 1 1 2 -> S=16 P=120, 6 INTEGER NUMBERS
 * NOTE: THE BOOK'S EXAMPLE SAYS M=2 N=2 AND S=15; THE CORRECT RESULT IS S=16 (A 2 X 3 MATRIX) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	double a[MAX][MAX] = {0};
	double sum = 0, product = 1;
	int m = 0, n = 0, i, j, integers = 0;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Row %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum = sum + a[i][j];
			product = product * a[i][j];
			/* A REAL NUMBER IS AN INTEGER WHEN IT EQUALS ITS INTEGER PART */
			if (a[i][j] == floor(a[i][j]))
			{
				integers++;
			}
		}
	}

	/* %G PRINTS 16 INSTEAD OF 16.000000, BUT KEEPS THE DECIMALS OF 2.5 */
	printf("s=%g p=%g\n", sum, product);
	printf("%d integer numbers\n", integers);

	return 0;
}
