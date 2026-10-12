/* SPLIT A PROGRAM INTO FUNCTIONS: THE SAME INIT, SORT AND PRINT WORK FOR ARRAYS OF ANY SIZE */
#include <stdio.h>  /* PRINTF */
#include <stdlib.h> /* RAND */

#define N 8

void init(int t[], int n);
void sort(int t[], int n);
void print(char name[], int t[], int n);

int main(void)
{
	int a[N], b[2 * N];

	init(a, N); /* THE SAME FUNCTION, TWO DIFFERENT ARRAYS */
	init(b, 2 * N);
	sort(a, N);
	sort(b, 2 * N);
	print("a", a, N);
	print("b", b, 2 * N);

	return 0;
}

void init(int t[], int n) /* FILL WITH RANDOM NUMBERS FROM 0 TO 99 */
{
	int i;

	for (i = 0; i < n; i++)
	{
		t[i] = rand() % 100;
	}
}

void sort(int t[], int n) /* BUBBLE SORT, REPEATED UNTIL NOTHING MOVES */
{
	int i, temp;
	int sorted = 0;

	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < n - 1; i++)
		{
			if (t[i] > t[i + 1])
			{
				temp = t[i];
				t[i] = t[i + 1];
				t[i + 1] = temp;
				sorted = 0;
			}
		}
	}
}

void print(char name[], int t[], int n)
{
	int i;

	printf("%s:", name);
	for (i = 0; i < n; i++)
	{
		printf(" %d", t[i]);
	}
	printf("\n");
}
