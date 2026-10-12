/* CULEGERE VIII.2.6 - COMMON WORDS OF TWO TEXTS
 * TWO TEXTS ARE READ, THEIR WORDS BEING SEPARATED BY ONE OR MORE SPACES; PRINT THE WORDS THAT
 * APPEAR IN BOTH TEXTS
 * EXAMPLE: ION MERGE LA PESTE AND DAN MERGE LA ION -> ION MERGE LA
 * ASSUMPTION: EACH COMMON WORD IS PRINTED ONCE, IN THE ORDER OF THE FIRST TEXT, AND A CAPITAL
 * LETTER IS DIFFERENT FROM A SMALL LETTER */
#include <stdio.h>  /* PRINTF, FGETS */
#include <string.h> /* STRLEN, STRCMP */

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

/* SPLITS THE TEXT INTO WORDS SEPARATED BY SPACES; RETURNS THE NUMBER OF WORDS */
int split_words(char text[], char words[][MAX_LEN])
{
	int i, k, len, count;

	len = strlen(text);
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
			words[count][k] = text[i];
			k++;
			i++;
		}
		/* SPACES AT THE END OF THE TEXT GIVE AN EMPTY WORD, WHICH IS NOT KEPT */
		if (k > 0)
		{
			words[count][k] = '\0';
			count++;
		}
	}
	return count;
}

int main(void)
{
	char text1[MAX_LEN], text2[MAX_LEN];
	char words1[MAX_WORDS][MAX_LEN], words2[MAX_WORDS][MAX_LEN];
	int n1, n2, i, j, in_second, seen_before;

	printf("First text: ");
	read_line(text1, MAX_LEN);
	printf("Second text: ");
	read_line(text2, MAX_LEN);

	n1 = split_words(text1, words1);
	n2 = split_words(text2, words2);

	printf("Common words:");
	for (i = 0; i < n1; i++)
	{
		/* IS WORD I OF THE FIRST TEXT ALSO IN THE SECOND TEXT? */
		in_second = 0;
		for (j = 0; j < n2; j++)
		{
			if (strcmp(words1[i], words2[j]) == 0)
			{
				in_second = 1;
			}
		}
		/* DID IT APPEAR EARLIER IN THE FIRST TEXT? THEN IT WAS ALREADY HANDLED */
		seen_before = 0;
		for (j = 0; j < i; j++)
		{
			if (strcmp(words1[i], words1[j]) == 0)
			{
				seen_before = 1;
			}
		}
		if (in_second == 1 && seen_before == 0)
		{
			printf(" %s", words1[i]);
		}
	}
	printf("\n");

	return 0;
}
