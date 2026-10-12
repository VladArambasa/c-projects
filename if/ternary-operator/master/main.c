/* TERNARY OPERATOR: A SHORT IF-ELSE THAT GIVES BACK A VALUE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, max;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	max = (a > b) ? a : b; /* IF A > B THEN A, OTHERWISE B */

	printf("The larger number is %d\n", max);
	printf("%d is %s\n", a, (a % 2 == 0) ? "even" : "odd");

	return 0;
}
