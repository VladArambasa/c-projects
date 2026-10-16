/* CULEGERE VIII.1.3 - PREFIXES OF A WORD
 * A WORD IS READ; PRINT ALL ITS PREFIXES (THE STRINGS MADE OF ITS FIRST CHARACTERS: AT LEAST
 * ONE CHARACTER, AT MOST ALL OF THEM)
 * EXAMPLE: TABLOU -> T TA TAB TABL TABLO TABLOU */
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

	printf("Prefixes:");
	for (k = 1; k <= len; k++)
	{
		/* THE PREFIX OF LENGTH K IS MADE OF THE FIRST K CHARACTERS */
		printf(" ");
		for (i = 0; i < k; i++)
		{
			printf("%c", word[i]);
		}
	}
	printf("\n");

	return 0;
}
