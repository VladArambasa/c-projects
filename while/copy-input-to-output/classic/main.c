/* COPY THE INPUT TO THE OUTPUT, ONE CHARACTER AT A TIME, UNTIL THE INPUT ENDS (CTRL+D) */
#include <stdio.h> /* GETCHAR, PUTCHAR, PRINTF, EOF */

int main(void)
{
	int c; /* INT, NOT CHAR: IT MUST HOLD ANY CHARACTER AND ALSO EOF */
	int chars = 0, lines = 0;

	while ((c = getchar()) != EOF) /* READ ONE CHARACTER AND TEST IT */
	{
		putchar(c);
		chars++;
		if (c == '\n')
		{
			lines++;
		}
	}

	printf("%d characters, %d lines\n", chars, lines);

	return 0;
}
