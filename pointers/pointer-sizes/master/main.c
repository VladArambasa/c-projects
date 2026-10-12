/* POINTER SIZES: EVERY POINTER HOLDS AN ADDRESS, SO ON COMMON MACHINES THEY ALL HAVE THE SAME SIZE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	printf("char *   : %zu bytes\n", sizeof(char *));
	printf("int *    : %zu bytes\n", sizeof(int *));
	printf("double * : %zu bytes\n", sizeof(double *));
	printf("void *   : %zu bytes\n", sizeof(void *));
	printf("but a char takes %zu byte and a double %zu bytes\n", sizeof(char), sizeof(double));

	return 0;
}
