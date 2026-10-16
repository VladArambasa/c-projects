/* CULEGERE VIII.1.13 - A WORD OF VOWELS AND A WORD OF CONSONANTS
 * N SMALL LETTERS ARE READ (N < 15); FORM A WORD WITH ONLY THE VOWELS AND A WORD WITH ONLY THE
 * CONSONANTS; PRINT FIRST THE WORD WITH MORE LETTERS (IF THEY ARE EQUAL, THE WORD OF VOWELS)
 * EXAMPLE: N=12, A V P O I N E R G E A S -> AOIEEA VPNRGS
 * ASSUMPTION: THE VOWELS ARE A, E, I, O, U */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 15 /* AT MOST 14 LETTERS AND THE NULL CHARACTER */

/* RETURNS 1 IF THE SMALL LETTER C IS A VOWEL, 0 OTHERWISE */
int is_vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	char vowels[MAX], consonants[MAX];
	char c = ' ';
	int n = 0, i, nv = 0, nc = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d letters: ", n);
	for (i = 0; i < n; i++)
	{
		/* THE SPACE BEFORE %C SKIPS THE SPACES BETWEEN THE LETTERS */
		scanf(" %c", &c);
		/* EACH LETTER IS ADDED AT THE END OF ITS WORD */
		if (is_vowel(c) == 1)
		{
			vowels[nv] = c;
			nv++;
		}
		else
		{
			consonants[nc] = c;
			nc++;
		}
	}
	/* THE NULL CHARACTER ENDS EACH WORD */
	vowels[nv] = '\0';
	consonants[nc] = '\0';

	if (nv >= nc)
	{
		printf("%s %s\n", vowels, consonants);
	}
	else
	{
		printf("%s %s\n", consonants, vowels);
	}

	return 0;
}
