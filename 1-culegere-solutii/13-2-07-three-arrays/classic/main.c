/* CULEGERE XIII.2.7 - THREE ARRAYS
 * GENERATE TWO ARRAYS WITH THE SAME NUMBER OF ELEMENTS (READ FROM THE KEYBOARD): A WITH NUMBERS
 * FROM 0 TO 99 AND B WITH NUMBERS FROM 1 TO 999. BUILD C: C[I] = A[I] - B[I] IF A[I] IS EVEN AND
 * B[I] ODD, C[I] = A[I] + B[I] IF A[I] IS ODD AND B[I] EVEN, C[I] = A[I] * B[I] IF THEY ARE BOTH
 * EVEN OR BOTH ODD. PRINT A, THEN B, THEN C, FOUR ELEMENTS ON A LINE
 * EXAMPLE: A[I]=4 B[I]=7 -> C[I]=-3; A[I]=5 B[I]=8 -> C[I]=13; A[I]=6 B[I]=10 -> C[I]=60
 * ASSUMPTION: AT MOST 100 ELEMENTS */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* RAND, SRAND */
#include <time.h>   /* TIME */

#define MAX 100

/* PRINTS THE ARRAY X, FOUR ELEMENTS ON A LINE */
void print_array(char name, int x[], int n)
{
	int i;

	printf("Array %c:\n", name);
	for (i = 0; i < n; i++)
	{
		printf("%8d", x[i]);
		if (i % 4 == 3 || i == n - 1)
		{
			printf("\n"); /* AFTER EVERY FOURTH ELEMENT AND AFTER THE LAST ONE */
		}
	}
}

int main(void)
{
	int a[MAX], b[MAX], c[MAX];
	int n = 0, i;

	srand(time(NULL)); /* OTHER NUMBERS AT EVERY RUN */

	printf("Number of elements: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;     /* 0 ... 99 */
		b[i] = rand() % 999 + 1; /* 1 ... 999 */

		if (a[i] % 2 == 0 && b[i] % 2 == 1)
		{
			c[i] = a[i] - b[i];
		}
		else if (a[i] % 2 == 1 && b[i] % 2 == 0)
		{
			c[i] = a[i] + b[i];
		}
		else
		{
			c[i] = a[i] * b[i]; /* SAME PARITY */
		}
	}

	print_array('A', a, n);
	print_array('B', b, n);
	print_array('C', c, n);

	return 0;
}
