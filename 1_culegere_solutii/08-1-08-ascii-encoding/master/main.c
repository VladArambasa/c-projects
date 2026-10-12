/* CULEGERE VIII.1.8 - TEXT CODED WITH ASCII CODES
 * A TEXT IS READ; PRINT IT CODED: EACH LETTER IS REPLACED BY ITS ASCII CODE, WITH ONE SPACE
 * BETWEEN TWO CODES AND THREE SPACES FOR EACH SPACE OF THE TEXT
 * EXAMPLE: AM UN MAR (CAPITAL A, THE REST SMALL) -> 65 109   117 110   109 97 114
 * ASSUMPTION: EVERY CHARACTER OTHER THAN THE SPACE (ALSO A DIGIT OR A SIGN) IS CODED */
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

	printf("Coded text: ");
	for (i = 0; i < len; i++)
	{
		if (text[i] == ' ')
		{
			printf("   "); /* A SPACE OF THE TEXT BECOMES THREE SPACES */
		}
		else
		{
			/* A CHARACTER PRINTED WITH %D SHOWS ITS ASCII CODE */
			printf("%d", text[i]);
			/* ONE SPACE BEFORE THE NEXT CODE OF THE SAME WORD */
			if (i + 1 < len && text[i + 1] != ' ')
			{
				printf(" ");
			}
		}
	}
	printf("\n");

	return 0;
}
