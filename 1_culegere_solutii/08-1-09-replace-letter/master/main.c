/* CULEGERE VIII.1.9 - REPLACE A LETTER
 * A TEXT AND TWO LETTERS ARE READ; IN THE TEXT, REPLACE THE FIRST LETTER WITH THE SECOND ONE
 * EXAMPLE: ABRACADABRA, LETTER B REPLACED BY G -> AGRACADAGRA
 * NOTE: THE BOOK'S EXAMPLE SAYS ABRAGADABRA; THE CORRECT RESULT IS AGRACADAGRA
 * (ABRAGADABRA IS WHAT WE GET WHEN C IS REPLACED BY G) */
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
	char old_letter = ' ', new_letter = ' ';
	int i, len;

	printf("Text: ");
	read_line(text, MAX_LEN);
	/* THE SPACE BEFORE %C SKIPS THE NEWLINE AND THE SPACES TYPED BEFORE THE LETTER */
	printf("Letter to replace: ");
	scanf(" %c", &old_letter);
	printf("Replace it with: ");
	scanf(" %c", &new_letter);

	/* EVERY APPEARANCE OF THE OLD LETTER IS OVERWRITTEN WITH THE NEW ONE */
	len = strlen(text);
	for (i = 0; i < len; i++)
	{
		if (text[i] == old_letter)
		{
			text[i] = new_letter;
		}
	}
	printf("New text: %s\n", text);

	return 0;
}
