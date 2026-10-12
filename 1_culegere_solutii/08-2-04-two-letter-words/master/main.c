/* CULEGERE VIII.2.4 - TWO-LETTER WORDS IN ALPHABETICAL ORDER
 * A TEXT IS READ; PRINT ITS WORDS MADE OF TWO LETTERS, IN ALPHABETICAL ORDER
 * EXAMPLE: TU AI FOST LA MARE -> AI LA TU
 * ASSUMPTION: THE WORDS ARE SEPARATED BY SPACES AND USE SMALL LETTERS, AS IN THE EXAMPLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX_LEN 257   /* 255 CHARACTERS, THE NEWLINE AND THE NULL CHARACTER */
#define MAX_WORDS 128 /* A TEXT OF 255 CHARACTERS HAS AT MOST 128 WORDS */

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
	char words[MAX_WORDS][3]; /* TWO LETTERS AND THE NULL CHARACTER */
	char aux[3];
	int i, j, len, start, count;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* TAKE THE WORDS ONE BY ONE AND KEEP THOSE WITH EXACTLY TWO LETTERS */
	count = 0;
	i = 0;
	while (i < len)
	{
		/* SKIP THE SPACES BEFORE THE WORD */
		while (i < len && text[i] == ' ')
		{
			i++;
		}
		/* THE WORD STARTS AT POSITION START AND ENDS BEFORE POSITION I */
		start = i;
		while (i < len && text[i] != ' ')
		{
			i++;
		}
		if (i - start == 2)
		{
			words[count][0] = text[start];
			words[count][1] = text[start + 1];
			words[count][2] = '\0';
			count++;
		}
	}

	/* SORTING BY INTERCHANGE; STRCMP TELLS WHICH WORD COMES FIRST IN THE DICTIONARY */
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (strcmp(words[i], words[j]) > 0)
			{
				strcpy(aux, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], aux);
			}
		}
	}

	printf("Two-letter words:");
	for (i = 0; i < count; i++)
	{
		printf(" %s", words[i]);
	}
	printf("\n");

	return 0;
}
