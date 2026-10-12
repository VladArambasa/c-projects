/* CULEGERE XIII.2.13 - PEASANT MULTIPLICATION
 * GRANDMA'S OLD WAY TO MULTIPLY A BY B: WRITE THEM SIDE BY SIDE, THEN UNDER A WRITE THE INTEGER
 * PART OF A/2 AND UNDER B WRITE 2*B, UNTIL THE A COLUMN REACHES 1. THE PRODUCT IS THE SUM OF THE
 * NUMBERS OF THE B COLUMN THAT STAND NEXT TO AN ODD NUMBER OF THE A COLUMN. PRINT THE TABLE
 * EXAMPLE: A=45 B=19 -> 19 + 76 + 152 + 608 = 855 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0;
	long long b = 0, product = 0; /* THE B COLUMN DOUBLES ON EVERY LINE, SO IT GROWS FAST */

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%lld", &b);

	printf("%6s %10s %12s\n", "a", "b", "product");
	while (a >= 1) /* THE LAST LINE IS THE ONE WITH A = 1 */
	{
		printf("%6d %10lld", a, b);
		if (a % 2 == 1)
		{
			printf(" %12lld", b); /* ODD A: THIS B GOES INTO THE SUM */
			product = product + b;
		}
		printf("\n");

		a = a / 2; /* THE NEXT LINE OF THE TABLE */
		b = b * 2;
	}
	printf("%30s\n", "===");
	printf("%30lld\n", product);

	return 0;
}
