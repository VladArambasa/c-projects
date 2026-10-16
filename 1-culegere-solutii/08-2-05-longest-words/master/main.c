/* CULEGERE VIII.2.5 - THE LONGEST WORDS
 * A TEXT OF AT MOST 255 CHARACTERS (LETTERS OF THE ENGLISH ALPHABET AND SPACES) IS READ;
 * PRINT THE WORDS OF MAXIMUM LENGTH
 * EXAMPLE: IONICA VREA SA MEARGA CU MIRCEA AL MARE -> IONICA MEARGA MIRCEA */
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
	char text[MAX_LEN];
	int i, k, len, start, max;

	printf("Text: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* FIRST PASS: THE LENGTH OF THE LONGEST WORD */
	max = 0;
	i = 0;
	while (i < len)
	{
		/* SKIP THE SPACES, THEN GO OVER THE WORD FROM START TO I */
		while (i < len && text[i] == ' ')
		{
			i++;
		}
		start = i;
		while (i < len && text[i] != ' ')
		{
			i++;
		}
		if (i - start > max)
		{
			max = i - start;
		}
	}

	/* SECOND PASS: PRINT EVERY WORD THAT HAS THIS LENGTH */
	printf("The longest words:");
	i = 0;
	while (i < len)
	{
		while (i < len && text[i] == ' ')
		{
			i++;
		}
		start = i;
		while (i < len && text[i] != ' ')
		{
			i++;
		}
		if (i - start == max)
		{
			printf(" ");
			for (k = start; k < i; k++)
			{
				printf("%c", text[k]);
			}
		}
	}
	printf("\n");

	return 0;
}
