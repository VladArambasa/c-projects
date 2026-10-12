/* REVERSE THE DIGITS OF A NUMBER (1234 -> 4321) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0;
	int reversed = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	while (n != 0)
	{
		reversed = reversed * 10 + n % 10; /* APPEND THE LAST DIGIT */
		n = n / 10;                        /* REMOVE THE LAST DIGIT */
	}

	printf("Reversed: %d\n", reversed);

	return 0;
}
