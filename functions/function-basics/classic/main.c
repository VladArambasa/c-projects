/* FUNCTIONS: DECLARE THEM (PROTOTYPE), DEFINE THEM ONCE, CALL THEM AS OFTEN AS NEEDED */
#include <stdio.h> /* PRINTF */

void say_hello(void);  /* PROTOTYPE: RETURNS NOTHING, VOID IN THE PARENTHESES MEANS NO PARAMETERS */
int square(int x); /* PROTOTYPE: TAKES AN INT, RETURNS AN INT */

int main(void)
{
	int result;

	say_hello();        /* CALL A FUNCTION THAT RETURNS NOTHING */
	result = square(5); /* CALL ONE AND KEEP WHAT IT RETURNS */
	printf("square(5) = %d\n", result);
	printf("square(12) = %d\n", square(12)); /* THE RESULT CAN BE USED DIRECTLY */

	return 0;
}

void say_hello(void) /* DEFINITION: THE CODE THAT RUNS */
{
	printf("Hello from a function!\n");
}

int square(int x)
{
	return x * x; /* SEND THE RESULT BACK TO THE CALLER */
}
