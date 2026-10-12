/* FILL AN ARRAY AND ADD IT UP (V2): A POINTER WALKS THE ARRAY, ONE SIMPLE STEP PER ELEMENT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define N 10

int main(void)
{
	int t[N];
	int *p;
	int i = 0;
	int sum = 0;

	for (p = t; p < t + N; p++) /* FROM THE FIRST ELEMENT TO JUST PAST THE LAST */
	{
		*p = i * i;
		i++;
	}

	for (p = t; p < t + N; p++)
	{
		sum = sum + *p;
		printf("%d ", *p);
	}
	printf("\nSum = %d\n", sum);

	return 0;
}
