/* CULEGERE XIII.3.10 - WORDS AND THEIR ECHOES
 * A TOURIST HEARS N WORDS; A MAGIC STONE SENDS BACK THE ECHO OF A WORD, WHICH IS THE WORD SAID FROM
 * ITS END. PRINT THE PAIRS MADE OF A WORD AND ITS ECHO
 * ASSUMPTION: A PAIR IS MADE OF TWO WORDS OF THE LIST AND EACH WORD BELONGS TO ONE PAIR AT MOST;
 * THE PAIRS ARE PRINTED ON ONE LINE, AS IN THE BOOK (AT MOST 100 WORDS OF AT MOST 30 LETTERS)
 * NOTE: THE BOOK'S EXAMPLE SAYS N=7 BUT LISTS 8 WORDS; THE CORRECT INPUT IS N=8 (WITH N=7 THE
 * LAST WORD, MAC, IS NEVER READ AND THE PAIR CAM MAC IS LOST)
 * EXAMPLE: 8 / CAM DES SED OAMENII LA AL DOILEA MAC -> CAM MAC   DES SED   LA AL */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXN 100
#define MAXLEN 31

char word[MAXN][MAXLEN];
int used[MAXN]; /* 1 FOR A WORD ALREADY PUT IN A PAIR */

/* 1 IF WORD B IS WORD A SAID FROM ITS END */
int is_echo(char a[], char b[])
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	int i;

	if (len_a != len_b)
	{
		return 0;
	}
	for (i = 0; i < len_a; i++)
	{
		if (a[i] != b[len_a - 1 - i])
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int n = 0, i, j, pairs;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d words: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%30s", word[i]);
	}

	/* EVERY WORD IS COMPARED WITH THE WORDS AFTER IT */
	pairs = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (used[i] == 0 && used[j] == 0 && is_echo(word[i], word[j]) == 1)
			{
				if (pairs > 0)
				{
					printf("   ");
				}
				printf("%s %s", word[i], word[j]);
				used[i] = 1;
				used[j] = 1;
				pairs++;
			}
		}
	}
	if (pairs == 0)
	{
		printf("No pairs");
	}
	printf("\n");

	return 0;
}
