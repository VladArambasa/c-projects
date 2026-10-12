/* CULEGERE VIII.1.10 - WORDS WITH THE SAME LETTERS
 * TWO WORDS ARE READ; CHECK IF THEY HAVE THE SAME LETTERS
 * EXAMPLE: MAR RAM -> YES
 * ASSUMPTION: ONLY WHICH LETTERS APPEAR MATTERS, NOT HOW MANY TIMES (MAMA AND AM -> YES) */
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

/* RETURNS 1 IF THE CHARACTER C APPEARS IN THE WORD W, 0 OTHERWISE */
int appears(char c, char w[])
{
	int i, len;

	len = strlen(w);
	for (i = 0; i < len; i++)
	{
		if (w[i] == c)
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	char w1[MAX_LEN], w2[MAX_LEN];
	int i, len1, len2, same;

	printf("First word: ");
	read_line(w1, MAX_LEN);
	printf("Second word: ");
	read_line(w2, MAX_LEN);
	len1 = strlen(w1);
	len2 = strlen(w2);

	same = 1;
	/* EVERY LETTER OF THE FIRST WORD MUST APPEAR IN THE SECOND WORD... */
	for (i = 0; i < len1; i++)
	{
		if (appears(w1[i], w2) == 0)
		{
			same = 0;
		}
	}
	/* ...AND EVERY LETTER OF THE SECOND WORD MUST APPEAR IN THE FIRST WORD */
	for (i = 0; i < len2; i++)
	{
		if (appears(w2[i], w1) == 0)
		{
			same = 0;
		}
	}

	if (same == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
