/* TRIANGLE TYPE FROM ITS SIDES: EQUILATERAL, ISOSCELES OR SCALENE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	double a = 0, b = 0, c = 0;

	printf("Enter the three sides: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a + b <= c || a + c <= b || b + c <= a) /* EACH SIDE MUST BE SHORTER THAN THE OTHER TWO */
	{
		printf("Not a triangle\n");
	}
	else if (a == b && b == c)
	{
		printf("Equilateral\n");
	}
	else if (a == b || b == c || a == c) /* TWO SIDES ARE EQUAL */
	{
		printf("Isosceles\n");
	}
	else
	{
		printf("Scalene\n");
	}

	return 0;
}
