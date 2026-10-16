/* CULEGERE VIII.1.6 - LETTERS AND THEIR FREQUENCY (VERSION 2)
 * A TEXT OF AT MOST 255 CHARACTERS IS READ; PRINT THE LETTERS USED IN IT AND HOW MANY TIMES
 * EACH OF THEM APPEARS
 * EXAMPLE: ANA ARE MERE -> A: 3  E: 3  M: 1  N: 1  R: 2
 * ASSUMPTION: A CAPITAL LETTER COUNTS AS ITS SMALL LETTER; THE LETTERS ARE PRINTED AS SMALL
 * LETTERS, IN ALPHABETICAL ORDER
 * IMPROVEMENT: ONE TRAVERSAL OF THE TEXT INSTEAD OF 26, WITH 26 COUNTERS (A FREQUENCY ARRAY) */
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
	int count[26] = {0}; /* COUNT[0] IS FOR A, COUNT[1] FOR B, ..., COUNT[25] FOR Z */
	int i, k, len;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* ONE TRAVERSAL: EACH LETTER INCREASES ITS OWN COUNTER */
	for (i = 0; i < len; i++)
	{
		if (isalpha(text[i]))
		{
			count[tolower(text[i]) - 'a']++;
		}
	}

	/* THE LETTERS WITH A COUNTER ABOVE 0 ARE THE LETTERS USED */
	for (k = 0; k < 26; k++)
	{
		if (count[k] > 0)
		{
			printf("%c: %d\n", 'a' + k, count[k]);
		}
	}

	return 0;
}
