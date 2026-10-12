/* CULEGERE VIII.1.4 - SUFFIXES OF A WORD
 * A WORD IS READ; PRINT ALL ITS SUFFIXES (THE STRINGS MADE OF ITS LAST CHARACTERS), FROM THE
 * SHORTEST ONE TO THE WHOLE WORD
 * EXAMPLE: TABLOU -> U OU LOU BLOU ABLOU TABLOU */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

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
	char word[MAX_LEN];
	int i, k, len;

	printf("Word: ");
	read_line(word, MAX_LEN);
	len = strlen(word);

	printf("Suffixes:");
	for (k = len - 1; k >= 0; k--)
	{
		/* THE SUFFIX THAT STARTS AT POSITION K GOES TO THE END OF THE WORD */
		printf(" ");
		for (i = k; i < len; i++)
		{
			printf("%c", word[i]);
		}
	}
	printf("\n");

	return 0;
}
