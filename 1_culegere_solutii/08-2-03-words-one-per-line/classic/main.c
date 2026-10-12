/* CULEGERE VIII.2.3 - THE WORDS ONE UNDER ANOTHER
 * A TEXT OF AT MOST 255 CHARACTERS IS READ; ITS WORDS ARE SEPARATED BY SPACE, DOT, COMMA,
 * QUESTION MARK AND EXCLAMATION MARK. PRINT THE WORDS OF THE TEXT ONE UNDER ANOTHER
 * EXAMPLE: PLEACA ION LA MARE? -> PLEACA / ION / LA / MARE (ONE WORD ON EACH LINE) */
#include <stdio.h>  /* PRINTF, FGETS */
#include <string.h> /* STRLEN */

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

/* RETURNS 1 IF C SEPARATES WORDS (SPACE . , ? !), 0 OTHERWISE */
int is_separator(char c)
{
	if (c == ' ' || c == '.' || c == ',' || c == '?' || c == '!')
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	char text[MAX_LEN];
	int i, len;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	printf("The words:\n");
	for (i = 0; i < len; i++)
	{
		/* THE CHARACTERS OF THE WORDS ARE PRINTED, THE SEPARATORS ARE NOT */
		if (is_separator(text[i]) == 0)
		{
			printf("%c", text[i]);
			/* AFTER THE LAST CHARACTER OF A WORD, GO TO A NEW LINE */
			if (i == len - 1 || is_separator(text[i + 1]) == 1)
			{
				printf("\n");
			}
		}
	}

	return 0;
}
