/* PROGRAM STRUCTURE: COPY THE INPUT TO THE OUTPUT IN UPPER CASE (END THE INPUT WITH CTRL+D) */

/* 1. PREPROCESSOR DIRECTIVES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* 2. DECLARATIONS */
int converted = 0;   /* GLOBAL VARIABLE: HOW MANY LETTERS WERE CHANGED */
int to_upper(int c); /* PROTOTYPE: THE FUNCTION IS DEFINED AFTER MAIN */

/* 3. FUNCTION DEFINITIONS */
int main(void)
{
	int c; /* INT, NOT CHAR: IT MUST ALSO HOLD EOF */

	while ((c = getchar()) != EOF) /* READ A CHARACTER */
	{
		putchar(to_upper(c)); /* CONVERT IT AND PRINT IT */
	}

	printf("\n%d letters converted\n", converted);
	return 0;
}

int to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		converted++;
		return c - 'a' + 'A'; /* SAME PLACE IN THE UPPERCASE RANGE */
	}
	return c; /* EVERYTHING ELSE STAYS THE SAME */
}
