/* #DEFINE: GIVE A NAME TO A VALUE; THE PREPROCESSOR REPLACES THE NAME BEFORE COMPILING */
#include <stdio.h> /* PRINTF */

#define PI 3.14159
#define TRUE 1
#define FALSE 0
#define MAX_STUDENTS 30
#define GREETING "Welcome to the C course" /* A MACRO CAN ALSO STAND FOR A STRING */
#define HIGH_BYTE_MASK 0xFF00

int main(void)
{
	double radius = 2;
	int value = 0x1234;

	printf("%s\n", GREETING);
	printf("Area of a circle with radius 2: %.2f\n", PI * radius * radius);
	printf("A class has at most %d students\n", MAX_STUDENTS);
	printf("High byte of 0x1234: 0x%X\n", (value & HIGH_BYTE_MASK) >> 8);
	printf("TRUE = %d, FALSE = %d\n", TRUE, FALSE);

	return 0;
}
