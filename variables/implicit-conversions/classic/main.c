/* IMPLICIT CONVERSIONS: C CONVERTS VALUES BY ITSELF WHEN TYPES ARE MIXED */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int i;
	short s;
	unsigned int u;
	double d = 15.75;
	long big = 100000;
	char c1 = 100, c2 = 100;

	i = d; /* DOUBLE TO INT: THE FRACTION IS DROPPED */
	printf("int i = 15.75   gives %d\n", i);

	s = big; /* 100000 DOES NOT FIT IN 16 BITS: ONLY THE LOW BITS ARE KEPT */
	printf("short s = 100000 gives %d\n", s);

	u = -1; /* NEGATIVE TO UNSIGNED WRAPS AROUND: -1 BECOMES THE LARGEST VALUE */
	printf("unsigned u = -1 gives %u\n", u);

	printf("char 100 + char 100 = %d\n", c1 + c2); /* CHARS BECOME INTS BEFORE THE ADDITION */

	printf("7 / 2 = %d, 7 / 2.0 = %.1f\n", 7 / 2, 7 / 2.0); /* ONE DOUBLE MAKES IT A REAL DIVISION */

	return 0;
}
