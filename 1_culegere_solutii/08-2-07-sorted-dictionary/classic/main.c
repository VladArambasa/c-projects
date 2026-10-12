/* CULEGERE VIII.2.7 - DICTIONARY OF A TEXT
 * A TEXT OF AT MOST 100 WORDS OR 1000 CHARACTERS, WITH WORDS SEPARATED BY SPACES, IS READ;
 * PUT ALL ITS DIFFERENT WORDS, WRITTEN WITH SMALL LETTERS, INTO A DICTIONARY KEPT IN
 * ALPHABETICAL ORDER (FROM A TO Z) AND PRINT THE DICTIONARY
 * EXAMPLE: ACESTA ESTE UN TEXT DE PROBA CU DOI DE ESTE -> ACESTA CU DE DOI ESTE PROBA TEXT UN
 * ASSUMPTION: ONLY THE SPACE SEPARATES WORDS (A PUNCTUATION SIGN STAYS PART OF ITS WORD) */
#include <stdio.h>  /* PRINTF, FGETS */
#include <string.h> /* STRLEN, STRCMP, STRCPY */
#include <ctype.h>  /* TOLOWER */

#define MAX_LEN 1002  /* 1000 CHARACTERS, THE NEWLINE AND THE NULL CHARACTER */
#define MAX_WORDS 100 /* AT MOST 100 WORDS */

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

/* PUTS THE WORD IN ITS ALPHABETICAL PLACE IN THE DICTIONARY, UNLESS IT IS ALREADY THERE;
 * RETURNS THE NEW NUMBER OF WORDS IN THE DICTIONARY */
int add_word(char dict[][MAX_LEN], int count, char word[])
{
	int pos, k;

	/* FIND THE FIRST DICTIONARY WORD THAT DOES NOT COME BEFORE THE NEW WORD */
	pos = 0;
	while (pos < count && strcmp(dict[pos], word) < 0)
	{
		pos++;
	}

	/* THE WORD IS ALREADY IN THE DICTIONARY: NOTHING TO ADD */
	if (pos < count && strcmp(dict[pos], word) == 0)
	{
		return count;
	}

	/* THE WORDS FROM POSITION POS ON MOVE ONE PLACE TO THE RIGHT TO MAKE ROOM */
	for (k = count; k > pos; k--)
	{
		strcpy(dict[k], dict[k - 1]);
	}
	strcpy(dict[pos], word);
	return count + 1;
}

int main(void)
{
	char text[MAX_LEN], word[MAX_LEN];
	char dict[MAX_WORDS][MAX_LEN];
	int i, k, len, count;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* THE DICTIONARY USES ONLY SMALL LETTERS */
	for (i = 0; i < len; i++)
	{
		text[i] = tolower(text[i]);
	}

	count = 0;
	i = 0;
	while (i < len)
	{
		/* SKIP THE SPACES BEFORE THE WORD */
		while (i < len && text[i] == ' ')
		{
			i++;
		}
		/* COPY THE WORD, CHARACTER BY CHARACTER */
		k = 0;
		while (i < len && text[i] != ' ')
		{
			word[k] = text[i];
			k++;
			i++;
		}
		word[k] = '\0';
		if (k > 0)
		{
			count = add_word(dict, count, word);
		}
	}

	printf("The dictionary:");
	for (i = 0; i < count; i++)
	{
		printf(" %s", dict[i]);
	}
	printf("\n");

	return 0;
}
