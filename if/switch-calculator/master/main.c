/* CALCULATOR WITH SWITCH: + - * / % */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0;
	char op = 0;

	printf("Enter an expression (example: 7 * 3): ");
	scanf("%d %c %d", &a, &op, &b);

	switch (op)
	{
	case '+':
		printf("%d\n", a + b);
		break;
	case '-':
		printf("%d\n", a - b);
		break;
	case '*':
		printf("%d\n", a * b);
		break;
	case '/':
		if (b == 0) /* DIVIDING BY ZERO IS NOT ALLOWED */
		{
			printf("Cannot divide by zero\n");
		}
		else
		{
			printf("%d\n", a / b);
		}
		break;
	case '%':
		if (b == 0)
		{
			printf("Cannot divide by zero\n");
		}
		else
		{
			printf("%d\n", a % b);
		}
		break;
	default:
		printf("Invalid operator\n");
	}

	return 0;
}
