/* MACROS WITH PARAMETERS: EACH CALL IS REPLACED BY THE BODY, WITH THE ARGUMENTS PUT IN */
#include <stdio.h> /* PRINTF */

#define MAX(A, B) ((A) > (B) ? (A) : (B)) /* PARENTHESES AROUND EACH PARAMETER AND THE WHOLE BODY */
#define SQUARE(X) ((X) * (X))
#define IS_EVEN(N) ((N) % 2 == 0)

int main(void)
{
	int x1 = 4, x2 = 9;

	printf("MAX(x1, x2)      = %d\n", MAX(x1, x2));      /* BECOMES ((X1) > (X2) ? (X1) : (X2)) */
	printf("MAX(-1.75, 0.5)  = %.2f\n", MAX(-1.75, 0.5)); /* ANY TYPE WORKS: THERE IS NO TYPE CHECK */
	printf("SQUARE(5)        = %d\n", SQUARE(5));
	printf("SQUARE(1.5)      = %.2f\n", SQUARE(1.5));
	printf("SQUARE(x1 + 1)   = %d\n", SQUARE(x1 + 1));   /* ((X1 + 1) * (X1 + 1)) */
	printf("IS_EVEN(10)      = %d\n", IS_EVEN(10));

	return 0;
}
