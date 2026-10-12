/* CULEGERE II.1.4 - NUMBER LEFT IN THE BOX
 * A BOX HOLDS THREE NUMBERS AND TWO OF THEM ARE TAKEN OUT. KNOWING THE SUM OF THE TWO NUMBERS
 * TAKEN OUT, PRINT THE NUMBER LEFT IN THE BOX
 * EXAMPLE: 5 12 8, SUM 13 -> 12 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0, sum = 0;

	printf("Numbers in the box: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("Sum of the numbers taken out: ");
	scanf("%d", &sum);

	/* FIND THE PAIR THAT GIVES THE SUM: THE THIRD NUMBER STAYED IN THE BOX */
	if (a + b == sum)
	{
		printf("%d\n", c);
	}
	else if (a + c == sum)
	{
		printf("%d\n", b);
	}
	else
	{
		printf("%d\n", a); /* B AND C WERE TAKEN OUT */
	}

	return 0;
}
