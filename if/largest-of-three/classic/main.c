/* LARGEST OF THREE NUMBERS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0, max;

	printf("Enter three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	max = a; /* ASSUME THE FIRST ONE IS THE LARGEST */
	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}

	printf("Largest is %d\n", max);

	return 0;
}
