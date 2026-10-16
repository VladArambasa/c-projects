/* CULEGERE VIII.2.2 - SHORTEST AND LONGEST WORD
 * A LINE READ FROM THE KEYBOARD HOLDS WORDS SEPARATED BY SPACES; PRINT THE MINIMUM AND THE
 * MAXIMUM LENGTH OF THE WORDS IN THE LINE
 * EXAMPLE: ANA ARE MERE FRUMOASE -> MIN=3 MAX=8 */
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
	int i, len, word_len, min, max;

	printf("Line: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	min = MAX_LEN; /* LONGER THAN ANY WORD, SO THE FIRST WORD WILL REPLACE IT */
	max = 0;
	i = 0;
	while (i < len)
	{
		/* SKIP THE SPACES BEFORE THE WORD */
		while (i < len && text[i] == ' ')
		{
			i++;
		}
		/* MEASURE THE WORD: COUNT ITS CHARACTERS UP TO THE NEXT SPACE */
		word_len = 0;
		while (i < len && text[i] != ' ')
		{
			word_len++;
			i++;
		}
		/* SPACES AT THE END OF THE LINE GIVE AN EMPTY WORD, WHICH IS NOT COUNTED */
		if (word_len > 0)
		{
			if (word_len < min)
			{
				min = word_len;
			}
			if (word_len > max)
			{
				max = word_len;
			}
		}
	}
	printf("min=%d max=%d\n", min, max);

	return 0;
}
