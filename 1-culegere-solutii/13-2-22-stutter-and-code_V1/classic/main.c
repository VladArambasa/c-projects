/* CULEGERE XIII.2.22 - STUTTER AND CODE
 * A STRING OF AT MOST 100 SMALL LETTERS IS READ. A STUTTER IS A GROUP OF LETTERS WRITTEN TWICE,
 * ONE RIGHT AFTER THE OTHER (ABBCABAB HAS THE STUTTERS B AND AB).
 * A) PRINT THE LONGEST STUTTER  B) CODE THE STRING: EVERY LETTER IS REPLACED BY THE LAST DIGIT OF
 * 2 TO THE POWER X, WHERE X IS THE ASCII CODE OF THE LETTER
 * EXAMPLE (IN SMALL LETTERS): ABBCABAB -> A) AB  B) 24482424
 * ASSUMPTION: IF SEVERAL STUTTERS HAVE THE MAXIMUM LENGTH, THE FIRST ONE IN THE STRING IS PRINTED
 * METHOD: THE LAST DIGIT OF THE POWER IS FOUND BY MULTIPLYING BY 2 AGAIN AND AGAIN */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXLEN 101 /* 100 LETTERS AND THE END MARK */

/* 1 IF THE L LETTERS STARTING ON POSITION I ARE WRITTEN AGAIN RIGHT AFTER THEMSELVES */
int is_stutter(char s[], int i, int l)
{
	int j;

	for (j = 0; j < l; j++)
	{
		if (s[i + j] != s[i + l + j])
		{
			return 0;
		}
	}
	return 1;
}

/* LAST DIGIT OF 2 TO THE POWER X: MULTIPLY BY 2, X TIMES, KEEPING ONLY THE LAST DIGIT */
int last_digit_of_power(int x)
{
	int i, digit = 1;

	for (i = 1; i <= x; i++)
	{
		digit = digit * 2 % 10;
	}
	return digit;
}

int main(void)
{
	char s[MAXLEN] = "";
	int len, l, i, found = 0, start = 0, best = 0;

	printf("String: ");
	scanf("%100s", s);
	len = strlen(s);

	/* A) TRY THE LONGEST GROUPS FIRST, SO THE FIRST STUTTER FOUND IS THE LONGEST ONE */
	for (l = len / 2; l >= 1 && found == 0; l--)
	{
		for (i = 0; i + 2 * l <= len && found == 0; i++)
		{
			if (is_stutter(s, i, l) == 1)
			{
				found = 1;
				start = i;
				best = l;
			}
		}
	}
	printf("a) ");
	if (found == 1)
	{
		for (i = start; i < start + best; i++)
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}
	else
	{
		printf("No stutter\n");
	}

	/* B) ONE DIGIT FOR EVERY LETTER */
	printf("b) ");
	for (i = 0; i < len; i++)
	{
		printf("%d", last_digit_of_power(s[i]));
	}
	printf("\n");
	return 0;
}
