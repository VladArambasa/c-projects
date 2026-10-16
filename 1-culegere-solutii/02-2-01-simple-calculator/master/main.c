/* CULEGERE II.2.1 - SIMPLE CALCULATOR
 * READ TWO NONZERO NUMBERS AND AN OPERATION SIGN (+ - * /); DO THE OPERATION AND PRINT THE
 * EXPRESSION, THE SIGN = AND THE VALUE
 * EXAMPLE: 10 6 * -> 10*6=60
 * ASSUMPTION: THE NUMBERS ARE INTEGERS; A DIVISION RESULT IS PRINTED WITH 2 DECIMALS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0;
	char op = ' ';

	printf("Two numbers and a sign (+ - * /): ");
	scanf("%d %d %c", &a, &b, &op);

	/* THE SIGN IS COMPARED WITH EACH OPERATION IN TURN */
	if (op == '+')
	{
		printf("%d+%d=%d\n", a, b, a + b);
	}
	else if (op == '-')
	{
		printf("%d-%d=%d\n", a, b, a - b);
	}
	else if (op == '*')
	{
		printf("%d*%d=%d\n", a, b, a * b);
	}
	else if (op == '/')
	{
		printf("%d/%d=%.2f\n", a, b, (double)a / b); /* REAL DIVISION: 10/6=1.67 */
	}
	else
	{
		printf("Unknown operation\n");
	}

	return 0;
}
