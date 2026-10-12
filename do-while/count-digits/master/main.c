/* COUNT THE DIGITS OF A NUMBER: WITH DO-WHILE, 0 CORRECTLY HAS ONE DIGIT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, copy;
	int count = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	copy = n;
	do
	{
		count++;           /* EVERY ROUND REMOVES ONE DIGIT */
		copy = copy / 10;
	} while (copy != 0);

	printf("%d has %d digit(s)\n", n, count);

	return 0;
}
