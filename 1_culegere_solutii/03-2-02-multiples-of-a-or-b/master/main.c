/* CULEGERE III.2.2 - MULTIPLES OF A OR B BELOW C
 * READ A, B, C AND PRINT IN INCREASING ORDER ALL THE NUMBERS SMALLER THAN C THAT ARE DIVISIBLE
 * BY A OR BY B. THE THREE GLASSES RULE (SWAPPING THROUGH AUX) PUTS THE SMALLER NUMBER IN A
 * AND THE BIGGER ONE IN B
 * ASSUMPTION: A, B >= 1 AND ONLY POSITIVE NUMBERS ARE PRINTED
 * ASSUMPTION: THE HINT STARTS THE LOOP AT B, BUT MULTIPLES OF A CAN BE SMALLER, SO IT STARTS AT A
 * EXAMPLE: A=6 B=4 C=20 -> 4 6 8 12 16 18 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, c = 0, aux, i;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);

	/* THE THREE GLASSES RULE: SWAP A AND B THROUGH AUX SO THAT A IS THE SMALLER ONE */
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}

	/* NO POSITIVE NUMBER BELOW A IS DIVISIBLE BY A OR BY B, SO THE LOOP STARTS AT A */
	for (i = a; i < c; i++)
	{
		if (i % a == 0 || i % b == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}
