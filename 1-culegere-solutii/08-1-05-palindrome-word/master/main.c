/* CULEGERE VIII.1.5 - PALINDROME WORD
 * A WORD IS READ; CHECK IF IT IS A PALINDROME (IT READS THE SAME FROM LEFT TO RIGHT AND FROM
 * RIGHT TO LEFT)
 * EXAMPLE: COJOC -> COJOC IS A PALINDROME */
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
	char word[MAX_LEN];
	int i, len, palindrome;

	printf("Word: ");
	read_line(word, MAX_LEN);
	len = strlen(word);

	/* THE FIRST CHARACTER WITH THE LAST ONE, THE SECOND WITH THE ONE BEFORE THE LAST, ...
	 * UP TO THE MIDDLE OF THE WORD */
	palindrome = 1;
	for (i = 0; i < len / 2; i++)
	{
		if (word[i] != word[len - 1 - i])
		{
			palindrome = 0;
		}
	}

	if (palindrome == 1)
	{
		printf("%s is a palindrome\n", word);
	}
	else
	{
		printf("%s is not a palindrome\n", word);
	}

	return 0;
}
