/* CULEGERE XIII.2.19 - LONGEST WORDS AND COMMON LETTERS
 * A TEXT OF AT MOST 255 CHARACTERS IS MADE OF WORDS SEPARATED BY ONE OR MORE SPACES. FIND THE WORDS
 * OF MAXIMUM LENGTH AND ALL THE LETTERS THAT APPEAR IN EVERY ONE OF THESE WORDS
 * EXAMPLE: THE CAT SAT ON A MAT -> WORDS OF MAXIMUM LENGTH (3): THE CAT SAT MAT; COMMON LETTERS: T
 * ASSUMPTION: CAPITAL AND SMALL FORMS ARE THE SAME LETTER; THE COMMON LETTERS ARE PRINTED SMALL */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

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

/* THE PLACE OF A LETTER IN THE ALPHABET (0 FOR A ... 25 FOR Z, SMALL OR CAPITAL), -1 FOR OTHERS */
int letter_index(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a';
	}
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A';
	}
	return -1;
}

/* SEEN[L] BECOMES 1 FOR EVERY LETTER L OF THE WORD (A LETTER WRITTEN TWICE IS MARKED ONCE) */
void mark_letters(char word[], int seen[])
{
	int j, l;
	int len = strlen(word);

	for (l = 0; l < 26; l++)
	{
		seen[l] = 0;
	}
	for (j = 0; j < len; j++)
	{
		l = letter_index(word[j]);
		if (l >= 0)
		{
			seen[l] = 1;
		}
	}
}

int main(void)
{
	char text[MAXLEN] = "";
	int count[26] = {0}; /* COUNT[L] = IN HOW MANY LONGEST WORDS LETTER L APPEARS */
	int seen[26];
	int n, i, l, len, max = 0, longest = 0, any = 0;

	printf("Text: ");
	read_line(text, MAXLEN);
	n = split_words(text);
	if (n == 0)
	{
		printf("No words\n");
		return 0;
	}

	/* THE MAXIMUM LENGTH OF A WORD */
	for (i = 0; i < n; i++)
	{
		len = strlen(words[i]);
		if (len > max)
		{
			max = len;
		}
	}

	/* PRINT THE LONGEST WORDS AND COUNT THEIR LETTERS */
	printf("Words of maximum length (%d):", max);
	for (i = 0; i < n; i++)
	{
		len = strlen(words[i]);
		if (len == max)
		{
			printf(" %s", words[i]);
			longest++;
			mark_letters(words[i], seen);
			for (l = 0; l < 26; l++)
			{
				count[l] = count[l] + seen[l];
			}
		}
	}
	printf("\n");

	/* A COMMON LETTER APPEARS IN ALL THE LONGEST WORDS */
	printf("Common letters:");
	for (l = 0; l < 26; l++)
	{
		if (count[l] == longest)
		{
			printf(" %c", 'a' + l);
			any = 1;
		}
	}
	if (any == 0)
	{
		printf(" none");
	}
	printf("\n");
	return 0;
}
