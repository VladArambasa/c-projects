/* DATA TYPE SIZES: SIZEOF GIVES THE NUMBER OF BYTES A TYPE OR A VARIABLE USES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int numbers[10];

	printf("char        : %zu byte\n", sizeof(char)); /* ALWAYS 1 */
	printf("short       : %zu bytes\n", sizeof(short));
	printf("int         : %zu bytes\n", sizeof(int)); /* 2 OR 4, DEPENDS ON THE MACHINE */
	printf("long        : %zu bytes\n", sizeof(long));
	printf("long long   : %zu bytes\n", sizeof(long long));
	printf("float       : %zu bytes\n", sizeof(float));
	printf("double      : %zu bytes\n", sizeof(double));
	printf("long double : %zu bytes\n", sizeof(long double));
	printf("int array[10]: %zu bytes\n", sizeof(numbers)); /* 10 * SIZEOF(INT) */

	return 0;
}
