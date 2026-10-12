/* CULEGERE III.6.1 - REMAINDER 7 WHEN DIVIDED BY 13
 * FOUR INTEGERS ARE READ ONE BY ONE; PRINT THE ONES THAT LEAVE REMAINDER 7 WHEN DIVIDED BY 13,
 * HOW MANY THERE ARE, AND THE PRODUCT OF THE OTHER NUMBERS
 * ASSUMPTION: A NEGATIVE NUMBER GETS ITS REMAINDER AS IN MATHS (0 TO 12), SO -6 LEAVES 7
 * EXAMPLE: 20 15 30 46 -> NUMBERS: 20 46  TOTAL: 2  PRODUCT: 450 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int numbers[4] = {0};
	int i, r;
	int total = 0;         /* HOW MANY NUMBERS LEAVE REMAINDER 7 */
	int others = 0;        /* HOW MANY NUMBERS GO INTO THE PRODUCT */
	long long product = 1; /* LONG LONG: A PRODUCT GROWS FAST */

	printf("The 4 numbers: ");
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &numbers[i]);
	}

	printf("Numbers:");
	for (i = 0; i < 4; i++)
	{
		r = numbers[i] % 13;
		if (r < 0) /* IN C, -6 % 13 IS -6; ADDING 13 GIVES THE REMAINDER FROM MATHS, 7 */
		{
			r = r + 13;
		}

		if (r == 7)
		{
			printf(" %d", numbers[i]);
			total++;
		}
		else
		{
			product = product * numbers[i];
			others++;
		}
	}
	printf("\n");
	printf("Total: %d\n", total);

	if (others == 0) /* EVERY NUMBER LEAVES REMAINDER 7: NOTHING TO MULTIPLY */
	{
		printf("Product: none (every number leaves remainder 7)\n");
	}
	else
	{
		printf("Product: %lld\n", product);
	}

	return 0;
}
