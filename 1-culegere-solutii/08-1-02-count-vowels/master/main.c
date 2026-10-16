/* CULEGERE VIII.1.2 - NUMBER OF VOWELS
 * A TEXT WRITTEN WITH SMALL LETTERS IS READ INTO A STRING; PRINT HOW MANY VOWELS IT HAS
 * EXAMPLE: ANA ARE MERE -> 6
 * ASSUMPTION: THE VOWELS ARE A, E, I, O, U */
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

/* RETURNS 1 IF THE SMALL LETTER C IS A VOWEL, 0 OTHERWISE */
int is_vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
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

	/* TEST EVERY CHARACTER OF THE TEXT */
	count = 0;
	for (i = 0; i < len; i++)
	{
		if (is_vowel(text[i]) == 1)
		{
			count++;
		}
	}
	printf("Number of vowels: %d\n", count);

	return 0;
}
