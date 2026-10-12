/* LITERAL CONSTANTS: HOW NUMBERS AND CHARACTERS ARE WRITTEN IN CODE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	/* INTEGERS: DECIMAL, OCTAL (STARTS WITH 0), HEXADECIMAL (STARTS WITH 0X) */
	printf("123 = %d, 0177 = %d, 0xFF = %d\n", 123, 0177, 0xFF);

	/* SUFFIXES: U = UNSIGNED, L = LONG */
	printf("50000U = %u, 100000L = %ld\n", 50000U, 100000L);

	/* A CHARACTER IS A SMALL NUMBER: ITS CODE */
	printf("'A' = %d, 'a' = %d, '0' = %d\n", 'A', 'a', '0');

	/* ESCAPE SEQUENCES */
	printf("tab[\t] quote[\"] backslash[\\]\n");
	printf("'\\101' (octal) = %c, '\\x41' (hex) = %c\n", '\101', '\x41');

	/* REAL NUMBERS ARE DOUBLE UNLESS THEY END IN F (FLOAT) */
	printf("3.14 = %f, 1.5e2 = %f, 1E-3 = %f\n", 3.14, 1.5e2, 1E-3);
	printf("sizeof(1.5F) = %zu, sizeof(1.5) = %zu\n", sizeof(1.5F), sizeof(1.5));

	return 0;
}
