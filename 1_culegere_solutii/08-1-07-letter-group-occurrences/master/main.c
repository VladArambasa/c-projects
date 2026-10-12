/* CULEGERE VIII.1.7 - OCCURRENCES OF A GROUP OF LETTERS
 * A TEXT OF AT MOST 255 CHARACTERS (WORDS SEPARATED BY ONE OR MORE SPACES) AND A CONTINUOUS
 * GROUP OF LETTERS ARE READ; PRINT HOW MANY TIMES THE GROUP APPEARS IN THE TEXT
 * EXAMPLE: ALINA MERGE SA CUMPERE MERE, GROUP ME -> 2
 * ASSUMPTION: OVERLAPPING APPEARANCES ARE ALL COUNTED (GROUP AA IN AAA -> 2) AND A CAPITAL
 * LETTER IS DIFFERENT FROM A SMALL LETTER */
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
	char text[MAX_LEN], group[MAX_LEN];
	int i, j, lt, lg, match, count;

	printf("Text: ");
	read_line(text, MAX_LEN);
	printf("Group of letters: ");
	read_line(group, MAX_LEN);
	lt = strlen(text);
	lg = strlen(group);

	/* TRY EVERY POSITION I WHERE THE GROUP STILL FITS INSIDE THE TEXT */
	count = 0;
	for (i = 0; i + lg <= lt; i++)
	{
		/* COMPARE THE GROUP WITH THE TEXT FROM POSITION I, CHARACTER BY CHARACTER */
		match = 1;
		for (j = 0; j < lg; j++)
		{
			if (text[i + j] != group[j])
			{
				match = 0;
			}
		}
		if (match == 1)
		{
			count++;
		}
	}
	printf("The group appears %d time(s)\n", count);

	return 0;
}
