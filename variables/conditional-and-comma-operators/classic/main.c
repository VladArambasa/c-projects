/* CONDITIONAL OPERATOR ?: AND COMMA OPERATOR */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int a = 7, b = 12;
	int max, i, j;

	max = (a > b) ? a : b; /* CONDITION ? VALUE IF TRUE : VALUE IF FALSE */
	printf("max = %d\n", max);
	printf("%d is %s\n", a, (a % 2 == 0) ? "even" : "odd");

	for (i = 0, j = 4; i < j; i++, j--) /* THE COMMA LETS ONE FOR LOOP HANDLE TWO COUNTERS */
	{
		printf("i = %d, j = %d\n", i, j);
	}

	return 0;
}
