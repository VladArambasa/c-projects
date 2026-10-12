/* CULEGERE VIII.1.1 - TEXT WITH CAPITAL LETTERS
 * A TEXT OF AT MOST 255 CHARACTERS IS READ; PRINT IT WRITTEN WITH CAPITAL LETTERS
 * EXAMPLE: CERC DE INFO, TYPED WITH SOME SMALL LETTERS -> CERC DE INFO */
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
	char text[MAX_LEN];
	int i, len;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* A SMALL LETTER BECOMES A CAPITAL LETTER, ANY OTHER CHARACTER STAYS THE SAME */
	for (i = 0; i < len; i++)
	{
		text[i] = toupper(text[i]);
	}
	printf("%s\n", text);

	return 0;
}
