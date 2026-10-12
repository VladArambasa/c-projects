/* CONSTANTS: VALUES THAT NEVER CHANGE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define PI 3.14159 /* SYMBOLIC CONSTANT: THE PREPROCESSOR REPLACES PI WITH 3.14159 */
#define TRUE 1
#define FALSE 0

int main(void)
{
	const int MINUTES_PER_HOUR = 60; /* CONST: READ ONLY, GIVE IT A VALUE RIGHT AWAY */
	const int BIRTH_YEAR = 2005;     /* UPPERCASE NAMES MARK CONSTANTS */
	double radius = 2;

	/* MINUTES_PER_HOUR = 10; WOULD NOT COMPILE: IT IS READ ONLY */

	printf("Minutes in a day: %d\n", 24 * MINUTES_PER_HOUR);
	printf("Age in 2026: %d\n", 2026 - BIRTH_YEAR);
	printf("Circle area: %.2f\n", PI * radius * radius);
	printf("TRUE = %d, FALSE = %d\n", TRUE, FALSE);

	return 0;
}
