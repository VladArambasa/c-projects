/* CULEGERE VIII.1.6 - LETTERS AND THEIR FREQUENCY (VERSION 1)
 * A TEXT OF AT MOST 255 CHARACTERS IS READ; PRINT THE LETTERS USED IN IT AND HOW MANY TIMES
 * EACH OF THEM APPEARS
 * EXAMPLE: ANA ARE MERE -> A: 3  E: 3  M: 1  N: 1  R: 2
 * ASSUMPTION: A CAPITAL LETTER COUNTS AS ITS SMALL LETTER; THE LETTERS ARE PRINTED AS SMALL
 * LETTERS, IN ALPHABETICAL ORDER
 * VERSION 1: THE TEXT IS TRAVERSED ONCE FOR EVERY LETTER OF THE ALPHABET (26 TRAVERSALS) */
#include <stdio.h>  /* PRINTF, FGETS */
#include <string.h> /* STRLEN */
#include <ctype.h>  /* TOLOWER */

#define MAX_LEN 257 /* 255 CHARACTERS, THE NEWLINE AND THE NULL CHARACTER */

/* READS A WHOLE LINE INTO S AND REMOVES THE NEWLINE FROM ITS END */
void read_line(char s[], int size)
{
	int len;

	if (fgets(s, size, stdin) == NULL)
	{
		s[0] = '\0'; /* NOTHING WAS READ: THE TEXT STAYS EMPTY */
	}
	len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
	}
}

int main(void)
{
	char text[MAX_LEN];
	char letter;
	int i, len, count;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		/* COUNT THIS LETTER, SMALL OR CAPITAL, IN THE WHOLE TEXT */
		count = 0;
		for (i = 0; i < len; i++)
		{
			if (tolower(text[i]) == letter)
			{
				count++;
			}
		}
		/* ONLY THE LETTERS THAT ARE USED ARE PRINTED */
		if (count > 0)
		{
			printf("%c: %d\n", letter, count);
		}
	}

	return 0;
}
