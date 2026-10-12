/* CULEGERE X.5.1 - LONGEST RUN OF EQUAL CHARACTERS
 * IN A TEXT OF AT MOST 255 CHARACTERS, PRINT THE LONGEST SEQUENCE OF IDENTICAL CHARACTERS
 * STANDING NEXT TO EACH OTHER; IF THERE ARE SEVERAL, PRINT THE FIRST ONE
 * EXAMPLE: AABSSSDADAAAB -> SSS (THE RUN AAA IS JUST AS LONG, BUT IT COMES LATER) */
#include <stdio.h>  /* PRINTF, FGETS, PUTCHAR */
#include <string.h> /* STRLEN */

#define MAX 255

int main(void)
{
	char text[MAX + 2] = ""; /* ROOM FOR THE ENTER KEY AND THE FINAL '\0' TOO */
	int len, i, start = 0, run = 0, best_start = 0, best_len = 0;

	printf("Text: ");
	fgets(text, sizeof(text), stdin);
	len = strlen(text);
	if (len > 0 && text[len - 1] == '\n')
	{
		text[len - 1] = '\0'; /* DROP THE ENTER KEY */
		len--;
	}

	for (i = 0; i < len; i++)
	{
		if (i > 0 && text[i] == text[i - 1])
		{
			run++; /* THE CURRENT RUN GOES ON */
		}
		else
		{
			start = i; /* A NEW RUN STARTS HERE */
			run = 1;
		}
		/* ONLY A STRICTLY LONGER RUN REPLACES THE BEST ONE, SO THE FIRST ONE IS KEPT */
		if (run > best_len)
		{
			best_len = run;
			best_start = start;
		}
	}

	for (i = best_start; i < best_start + best_len; i++)
	{
		putchar(text[i]);
	}
	printf("\n");

	return 0;
}
