/* MATH.H: COMMON MATH FUNCTIONS; ON LINUX THE MATH LIBRARY MUST ALSO BE LINKED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define PI 3.14159265358979

int main(void)
{
	double a = 16, b = 2.7, c = -3.5;

	printf("sqrt(16)     = %.2f\n", sqrt(a));
	printf("pow(2, 10)   = %.0f\n", pow(2, 10));
	printf("fabs(-3.5)   = %.2f\n", fabs(c));     /* ABSOLUTE VALUE OF A DOUBLE */
	printf("floor(2.7)   = %.0f\n", floor(b));    /* DOWN TO A WHOLE NUMBER */
	printf("ceil(2.7)    = %.0f\n", ceil(b));     /* UP TO A WHOLE NUMBER */
	printf("round(-3.5)  = %.0f\n", round(c));    /* HALVES GO AWAY FROM ZERO */
	printf("sin(PI / 2)  = %.2f\n", sin(PI / 2)); /* ANGLES ARE IN RADIANS */
	printf("cos(PI)      = %.2f\n", cos(PI));
	printf("hypot(3, 4)  = %.2f\n", hypot(3, 4)); /* SQRT(3 * 3 + 4 * 4) */

	return 0;
}
