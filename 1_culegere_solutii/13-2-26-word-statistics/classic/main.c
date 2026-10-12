/* CULEGERE XIII.2.26 - WORD STATISTICS
 * A TEXT OF AT MOST 255 CHARACTERS IS READ; THE ONLY SEPARATOR BETWEEN WORDS IS THE SPACE.
 * A) FOR EVERY WORD PRINT ITS PLACE IN THE TEXT (WHICH WORD IT IS), ITS NUMBER OF LETTERS AND THE
 * SUM OF THE ASCII CODES OF ITS LETTERS  B) PRINT HOW MANY TIMES EACH WORD APPEARS IN THE TEXT
 * EXAMPLE: ANA ARE MERE ANA -> A) 1 ANA 3 208, 2 ARE 3 216, 3 MERE 4 297, 4 ANA 3 208
 *          B) ANA 2, ARE 1, MERE 1
 * ASSUMPTION: EVERY CHARACTER OF A WORD COUNTS AS A LETTER; SEVERAL SPACES IN A ROW ARE ONE
 * SEPARATOR; CAPITAL AND SMALL LETTERS ARE DIFFERENT (THEIR ASCII CODES DIFFER) */
#include <stdio.h>  /* PRINTF, FGETS */
#include <string.h> /* STRLEN, STRCMP */

#define MAXLEN 257 /* 255 CHARACTERS, THE NEW LINE MARK AND THE END MARK */
#define MAXW 128   /* 255 CHARACTERS HOLD AT MOST 128 WORDS */

char words[MAXW][MAXLEN];

/* READS A LINE FROM THE KEYBOARD AND REMOVES THE NEW LINE MARK AT ITS END */
void read_line(char s[], int size)
{
	int len;

	if (fgets(s, size, stdin) == NULL)
	{
		s[0] = '\0';
	}
	len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
	}
}

/* CUTS THE TEXT INTO WORDS (KEPT IN THE TABLE WORDS); RETURNS HOW MANY WORDS THERE ARE */
int split_words(char text[])
{
	int i, k = 0, count = 0;
	int len = strlen(text);

	for (i = 0; i <= len; i++)
	{
		if (text[i] != ' ' && text[i] != '\0')
		{
			words[count][k] = text[i]; /* ONE MORE CHARACTER OF THE CURRENT WORD */
			k++;
		}
		else if (k > 0)
		{
			words[count][k] = '\0'; /* A SPACE OR THE END OF THE TEXT CLOSES THE WORD */
			count++;
			k = 0;
		}
	}
	return count;
}

/* THE SUM OF THE ASCII CODES OF THE LETTERS OF A WORD */
int ascii_sum(char word[])
{
	int i, sum = 0;
	int len = strlen(word);

	for (i = 0; i < len; i++)
	{
		sum = sum + word[i]; /* A CHARACTER IS STORED AS ITS ASCII CODE */
	}
	return sum;
}

int main(void)
{
	char text[MAXLEN] = "";
	int n, i, j, len, sum, times, before;

	printf("Text: ");
	read_line(text, MAXLEN);
	n = split_words(text);

	/* A) PLACE, NUMBER OF LETTERS AND SUM OF THE ASCII CODES OF EVERY WORD */
	printf("a)\n");
	for (i = 0; i < n; i++)
	{
		len = strlen(words[i]);
		sum = ascii_sum(words[i]);
		printf("Word %d: %s, %d letters, ASCII sum %d\n", i + 1, words[i], len, sum);
	}

	/* B) A WORD IS COUNTED AT ITS FIRST APPEARANCE ONLY */
	printf("b)\n");
	for (i = 0; i < n; i++)
	{
		before = 0;
		for (j = 0; j < i; j++)
		{
			if (strcmp(words[j], words[i]) == 0)
			{
				before = 1; /* THIS WORD WAS ALREADY COUNTED */
			}
		}
		if (before == 0)
		{
			times = 0;
			for (j = i; j < n; j++)
			{
				if (strcmp(words[j], words[i]) == 0)
				{
					times++;
				}
			}
			printf("%s: %d\n", words[i], times);
		}
	}
	return 0;
}
