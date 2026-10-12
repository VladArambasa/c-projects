/* PRINT THE NUMBERS FROM 1 TO N */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;

	printf("Enter n: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}
