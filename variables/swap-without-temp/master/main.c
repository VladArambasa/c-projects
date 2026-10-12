/* SWAP TWO NUMBERS WITHOUT A THIRD VARIABLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	a = a + b; /* A HOLDS THE SUM */
	b = a - b; /* SUM - OLD B = OLD A */
	a = a - b; /* SUM - OLD A = OLD B */

	printf("After swap: a = %d, b = %d\n", a, b);

	return 0;
}
