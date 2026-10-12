/* STRONG NUMBER (V2): THE TEN DIGIT FACTORIALS ARE STORED IN A TABLE INSTEAD OF RECOMPUTED */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; /* 0! TO 9! */
	int n = 0, temp;
	int sum = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	temp = n;
	while (temp > 0)
	{
		sum = sum + fact[temp % 10]; /* ONE LOOKUP PER DIGIT */
		temp = temp / 10;
	}

	if (n > 0 && sum == n)
	{
		printf("%d is a strong number\n", n);
	}
	else
	{
		printf("%d is not a strong number\n", n);
	}

	return 0;
}
