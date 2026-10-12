/* AREA AND CIRCUMFERENCE OF A CIRCLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define PI 3.14159265 /* OUR OWN CONSTANT: M_PI IS NOT PART OF STANDARD C */

int main(void)
{
	double radius = 0;

	printf("Enter the radius: ");
	scanf("%lf", &radius);

	printf("Area = %.2f\n", PI * radius * radius);
	printf("Circumference = %.2f\n", 2 * PI * radius);

	return 0;
}
