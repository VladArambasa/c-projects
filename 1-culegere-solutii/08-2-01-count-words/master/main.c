/* CULEGERE VIII.2.1 - NUMBER OF WORDS
 * A TEXT IS READ INTO A STRING; COUNT ITS WORDS, THE SEPARATORS BEING THE SPACE, THE DOT AND
 * THE COMMA
 * EXAMPLE: ANA ARE MERE, PERE SI PRUNE. -> 6 WORDS */
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

/* RETURNS 1 IF C SEPARATES WORDS (SPACE, DOT, COMMA), 0 OTHERWISE */
int is_separator(char c)
{
	if (c == ' ' || c == '.' || c == ',')
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	char text[MAX_LEN];
	int i, len, count;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* A WORD STARTS WHERE A CHARACTER THAT IS NOT A SEPARATOR COMES
	 * AT THE BEGINNING OF THE TEXT OR RIGHT AFTER A SEPARATOR */
	count = 0;
	for (i = 0; i < len; i++)
	{
		if (is_separator(text[i]) == 0 && (i == 0 || is_separator(text[i - 1]) == 1))
		{
			count++;
		}
	}
	printf("Number of words: %d\n", count);

	return 0;
}
