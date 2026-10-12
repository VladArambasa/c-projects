/* FILL AN ARRAY AND ADD IT UP USING INDEXES (T[I] MEANS *(T + I): AN ADDRESS COMPUTATION EACH TIME) */
#include <stdio.h> /* PRINTF */

#define N 10

int main(void)
{
	int t[N];
	int i;
	int sum = 0;

	for (i = 0; i < N; i++)
	{
		t[i] = i * i;
	}

	for (i = 0; i < N; i++)
	{
		sum = sum + t[i];
		printf("%d ", t[i]);
	}
	printf("\nSum = %d\n", sum);

	return 0;
}
