/* RETURN MORE THAN ONE VALUE: THE FUNCTION WRITES ITS RESULTS AT ADDRESSES GIVEN BY THE CALLER */
#include <stdio.h> /* PRINTF */

void min_max(int t[], int n, int *min, int *max)
{
	int i;

	*min = t[0];
	*max = t[0];
	for (i = 1; i < n; i++)
	{
		if (t[i] < *min)
		{
			*min = t[i];
		}
		if (t[i] > *max)
		{
			*max = t[i];
		}
	}
}

void divide(int a, int b, int *quotient, int *remainder)
{
	*quotient = a / b;
	*remainder = a % b;
}

int main(void)
{
	int t[6] = {4, -2, 9, 0, 7, 3};
	int low, high, q, r;

	min_max(t, 6, &low, &high); /* LOW AND HIGH ARE FILLED IN BY THE FUNCTION */
	printf("min = %d, max = %d\n", low, high);

	divide(17, 5, &q, &r);
	printf("17 / 5 = %d, remainder %d\n", q, r);

	return 0;
}
