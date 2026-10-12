/* ARRAYS AS PARAMETERS: THE FUNCTION RECEIVES ONLY THE ADDRESS, SO THE SIZE MUST BE PASSED TOO */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int sum(int t[], int n) /* INT T[] IN A PARAMETER LIST MEANS INT *T */
{
	int i;
	int s = 0;

	for (i = 0; i < n; i++)
	{
		s = s + t[i];
	}
	return s;
}

void double_all(int t[], int n) /* CHANGES MADE HERE ARE SEEN BY THE CALLER */
{
	int i;

	for (i = 0; i < n; i++)
	{
		t[i] = t[i] * 2;
	}
}

void show_size(int *t)
{
	printf("sizeof inside a function: %zu bytes (only a pointer)\n", sizeof(t));
}

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int b[3] = {10, 20, 30};

	printf("sum(a) = %d, sum(b) = %d\n", sum(a, 5), sum(b, 3)); /* ONE FUNCTION, ANY SIZE */

	double_all(a, 5);
	printf("a after double_all: %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);

	printf("sizeof in main: %zu bytes (the whole array)\n", sizeof(a));
	show_size(a);

	return 0;
}
