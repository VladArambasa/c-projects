/* ARITHMETIC OPERATORS: + - * / % */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 17, b = 5;
	double x = 17, y = 5;

	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);  /* INT / INT DROPS THE FRACTION */
	printf("%d %% %d = %d\n", a, b, a % b); /* REMAINDER, INTEGERS ONLY */
	printf("%.1f / %.1f = %.2f\n", x, y, x / y); /* REAL DIVISION */
	printf("347 %% 10 = %d (last digit)\n", 347 % 10);
	/* DIVISION CUTS TOWARD ZERO, THE REMAINDER TAKES THE SIGN OF THE LEFT NUMBER */
	printf("-17 / 5 = %d, -17 %% 5 = %d\n", -17 / 5, -17 % 5);

	return 0;
}
