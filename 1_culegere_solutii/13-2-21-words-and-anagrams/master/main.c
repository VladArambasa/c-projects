/* CULEGERE XIII.2.21 - WORDS AND ANAGRAMS
 * A TEXT OF AT MOST 255 CHARACTERS, ALL CAPITALS, HAS WORDS SEPARATED BY ANY NUMBER OF SPACES.
 * A) PRINT ALL THE WORDS OF THE TEXT  B) FIND THE LENGTH OF THE SHORTEST WORD  C) READ A WORD AND
 * PRINT THE WORDS OF THE TEXT WITH THE SAME LENGTH AND EXACTLY THE SAME LETTERS AS IT
 * EXAMPLE: ROMA  AMOR CAR   MORA RAC, WORD RAMO
 *          -> A) ROMA AMOR CAR MORA RAC  B) 3  C) ROMA AMOR MORA */
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

/* 1 IF THE TWO WORDS HAVE THE SAME LENGTH AND EXACTLY THE SAME LETTERS, 0 OTHERWISE */
int same_letters(char a[], char b[])
{
	int count[26] = {0};
	int i, len_a = strlen(a), len_b = strlen(b);

	if (len_a != len_b)
	{
		return 0;
	}
	for (i = 0; i < len_a; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			count[a[i] - 'A']++; /* A LETTER OF THE FIRST WORD ADDS ONE */
		}
		if (b[i] >= 'A' && b[i] <= 'Z')
		{
			count[b[i] - 'A']--; /* A LETTER OF THE SECOND WORD TAKES ONE AWAY */
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			return 0; /* SOME LETTER APPEARS MORE TIMES IN ONE OF THE WORDS */
		}
	}
	return 1;
}

int main(void)
{
	char text[MAXLEN] = "", word[MAXLEN] = "";
	int n, i, len, min, any = 0;

	printf("Text: ");
	read_line(text, MAXLEN);
	n = split_words(text);
	if (n == 0)
	{
		printf("No words\n");
		return 0;
	}

	/* A) THE WORDS, ONE ON EACH LINE */
	printf("a) The words:\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", words[i]);
	}

	/* B) THE LENGTH OF THE SHORTEST WORD */
	min = strlen(words[0]);
	for (i = 1; i < n; i++)
	{
		len = strlen(words[i]);
		if (len < min)
		{
			min = len;
		}
	}
	printf("b) Length of the shortest word: %d\n", min);

	/* C) THE WORDS MADE OF THE SAME LETTERS AS THE GIVEN WORD */
	printf("Word: ");
	scanf("%255s", word);
	printf("c)");
	for (i = 0; i < n; i++)
	{
		if (same_letters(words[i], word) == 1)
		{
			printf(" %s", words[i]);
			any = 1;
		}
	}
	if (any == 0)
	{
		printf(" No word");
	}
	printf("\n");
	return 0;
}
