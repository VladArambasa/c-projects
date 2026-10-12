/* RELATIONAL AND LOGICAL OPERATORS: THE RESULT IS 1 (TRUE) OR 0 (FALSE) */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int a = 5, b = 3;

	printf("a == b : %d\n", a == b);
	printf("a != b : %d\n", a != b);
	printf("a >  b : %d\n", a > b);
	printf("a <= b : %d\n", a <= b);

	printf("(a > 0) && (b > 0) : %d\n", (a > 0) && (b > 0)); /* AND: BOTH MUST BE TRUE */
	printf("(a > 9) || (b > 0) : %d\n", (a > 9) || (b > 0)); /* OR: ONE IS ENOUGH */
	printf("!(a > b)           : %d\n", !(a > b));            /* NOT: REVERSES THE RESULT */
	printf("a && -b            : %d\n", a && -b);             /* ANY NON-ZERO VALUE IS TRUE */

	/* SHORT CIRCUIT: B IS 0, SO THE LEFT SIDE IS FALSE AND A / B IS NEVER COMPUTED */
	b = 0;
	printf("(b != 0) && (a / b > 1) : %d\n", (b != 0) && (a / b > 1));

	return 0;
}
