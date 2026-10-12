/* DIGITAL ROOT: ADD THE DIGITS AGAIN AND AGAIN UNTIL ONE DIGIT IS LEFT (9875 -> 29 -> 11 -> 2) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, sum;

	printf("Enter a positive number: ");
	scanf("%d", &n);

	printf("%d", n);
	do
	{
		sum = 0;
		while (n > 0) /* ADD THE DIGITS OF N */
		{
			sum = sum + n % 10;
			n = n / 10;
		}
		n = sum;
		printf(" -> %d", n);
	} while (n > 9); /* MORE THAN ONE DIGIT: DO IT AGAIN */
	printf("\n");

	return 0;
}
