/* CULEGERE II.3.7 - CLASS LETTER
 * THE 5TH GRADE PUPILS ARE PUT INTO CLASSES OF 25, IN THE ORDER OF THEIR 4TH GRADE AVERAGES.
 * RADU IS IN PLACE X: PRINT HIS CLASS (A, B, C, D OR E)
 * EXAMPLE: X=73 -> C */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int x = 0, q;

	printf("x = ");
	scanf("%d", &x);

	/* WITH X - 1, PLACES 1-25 GIVE THE QUOTIENT 0, 26-50 GIVE 1, 51-75 GIVE 2 ... */
	q = (x - 1) / 25;

	if (q == 0)
	{
		printf("class A\n");
	}
	else if (q == 1)
	{
		printf("class B\n");
	}
	else if (q == 2)
	{
		printf("class C\n");
	}
	else if (q == 3)
	{
		printf("class D\n");
	}
	else
	{
		printf("class E\n");
	}

	return 0;
}
