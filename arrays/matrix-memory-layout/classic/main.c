/* MATRIX IN MEMORY: THE ROWS ARE STORED ONE AFTER ANOTHER IN A SINGLE BLOCK */
#include <stdio.h> /* PRINTF */

#define ROWS 3
#define COLS 4

int main(void)
{
	int t[ROWS][COLS];
	int *p = &t[0][0]; /* POINTER TO THE VERY FIRST ELEMENT */
	int i, j, k;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			t[i][j] = i * 10 + j; /* THE VALUE SHOWS ROW AND COLUMN */
		}
	}

	printf("As a table:\n");
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%4d", t[i][j]);
		}
		printf("\n");
	}

	printf("As memory sees it:\n");
	for (k = 0; k < ROWS * COLS; k++)
	{
		printf("%4d", p[k]); /* ONE LONG ROW: 0 1 2 3 10 11 ... */
	}
	printf("\n");

	/* THE SAME ELEMENT, REACHED IN TWO WAYS */
	printf("t[2][1] = %d, *(p + 2 * COLS + 1) = %d\n", t[2][1], *(p + 2 * COLS + 1));
	printf("Distance from t[0][0] to t[1][0]: %d elements\n", (int)(&t[1][0] - &t[0][0]));

	return 0;
}
