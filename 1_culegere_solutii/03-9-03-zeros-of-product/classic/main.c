/* CULEGERE III.9.3 - ZEROS AT THE END OF A PRODUCT
 * N NUMBERS ARE READ; IN HOW MANY ZEROS DOES THEIR PRODUCT END?
 * IDEA: EVERY ZERO AT THE END COMES FROM A 10 = 2 * 5, SO THE ANSWER IS THE SMALLER OF THE
 * NUMBER OF FACTORS 2 AND THE NUMBER OF FACTORS 5 IN ALL THE NUMBERS TOGETHER; THE PRODUCT
 * ITSELF IS NEVER COMPUTED, BECAUSE IT QUICKLY GETS TOO BIG FOR ANY TYPE
 * EXAMPLE: N=4: 5 4 10 25 -> 3 ZEROS (THE PRODUCT IS 5000) */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, x = 0, i;
	int twos = 0, fives = 0, zeros;
	int has_zero = 0; /* BECOMES 1 IF ONE OF THE NUMBERS IS 0 */

	printf("n = ");
	scanf("%d", &n);

	printf("The %d numbers: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x == 0) /* A FACTOR 0 MAKES THE PRODUCT 0 (AND 0 / 2 = 0 WOULD LOOP FOREVER) */
		{
			has_zero = 1;
		}
		else
		{
			while (x % 2 == 0) /* TAKE OUT EVERY FACTOR 2 */
			{
				twos++;
				x = x / 2;
			}
			while (x % 5 == 0) /* TAKE OUT EVERY FACTOR 5 */
			{
				fives++;
				x = x / 5;
			}
		}
	}

	if (has_zero == 1)
	{
		printf("The product is 0\n");
	}
	else
	{
		zeros = twos; /* EVERY 10 NEEDS ONE 2 AND ONE 5: THE RARER FACTOR DECIDES */
		if (fives < zeros)
		{
			zeros = fives;
		}
		printf("%d %s\n", zeros, (zeros == 1) ? "zero" : "zeros");
	}

	return 0;
}
