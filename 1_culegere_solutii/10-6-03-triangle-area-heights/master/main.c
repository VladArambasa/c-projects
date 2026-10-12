/* CULEGERE X.6.3 - TRIANGLE AREA AND HEIGHTS
 * THE THREE SIDES OF A TRIANGLE ARE READ (POSITIVE REAL NUMBERS); PRINT ITS AREA, THE LENGTHS OF
 * ITS THREE HEIGHTS AND ITS KIND: EQUILATERAL, ISOSCELES, RIGHT, RIGHT ISOSCELES OR SCALENE
 * EXAMPLE: 3 4 5 -> AREA = 6.00, HEIGHTS 4.00 3.00 2.40, RIGHT TRIANGLE
 * ASSUMPTION: REAL NUMBERS ARE COMPARED WITH A TOLERANCE OF 0.001, SO A SIDE LIKE THE SQUARE ROOT
 * OF 2 MAY BE TYPED ROUNDED (1 1 1.4142 IS A RIGHT ISOSCELES TRIANGLE) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define EPS 0.001

/* 1 IF THE REAL NUMBERS U AND V ARE EQUAL, UP TO THE TOLERANCE EPS */
int equal(double u, double v)
{
	if (fabs(u - v) < EPS)
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	double a = 0, b = 0, c = 0, p, area;
	int right, isosceles;

	printf("The three sides: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	/* HERON'S FORMULA, WITH P = HALF OF THE PERIMETER */
	p = (a + b + c) / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("Area = %.2f\n", area);

	/* AREA = SIDE * HEIGHT / 2, SO HEIGHT = 2 * AREA / SIDE */
	printf("Height to side a = %.2f\n", 2 * area / a);
	printf("Height to side b = %.2f\n", 2 * area / b);
	printf("Height to side c = %.2f\n", 2 * area / c);

	/* PYTHAGORAS: THE SQUARE OF ONE SIDE IS THE SUM OF THE SQUARES OF THE OTHER TWO */
	right = equal(a * a + b * b, c * c) || equal(a * a + c * c, b * b) ||
	        equal(b * b + c * c, a * a);
	isosceles = equal(a, b) || equal(a, c) || equal(b, c);

	/* THE MOST PRECISE NAME FIRST: AN EQUILATERAL TRIANGLE IS ALSO ISOSCELES */
	if (equal(a, b) && equal(b, c))
	{
		printf("Equilateral triangle\n");
	}
	else if (right && isosceles)
	{
		printf("Right isosceles triangle\n");
	}
	else if (right)
	{
		printf("Right triangle\n");
	}
	else if (isosceles)
	{
		printf("Isosceles triangle\n");
	}
	else
	{
		printf("Scalene triangle\n");
	}

	return 0;
}
