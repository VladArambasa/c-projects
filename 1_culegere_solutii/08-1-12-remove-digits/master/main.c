/* CULEGERE VIII.1.12 - REMOVE THE DIGITS
 * A STRING IS READ; REMOVE FROM IT ALL THE DIGIT CHARACTERS IT CONTAINS
 * EXAMPLE: ANA ARE 3 MERE -> ANA ARE  MERE
 * NOTE: THE BOOK'S EXAMPLE SAYS ANA ARE MERE; THE CORRECT RESULT IS ANA ARE  MERE, WITH TWO
 * SPACES, BECAUSE ONLY THE DIGIT IS REMOVED AND THE SPACES AROUND IT STAY */
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
	int i, k, len;

	printf("String: ");
	read_line(text, MAX_LEN);
	len = strlen(text);

	/* THE CHARACTERS THAT ARE NOT DIGITS ARE MOVED TO THE FRONT, ONE AFTER THE OTHER;
	 * K IS THE PLACE OF THE NEXT CHARACTER THAT IS KEPT */
	k = 0;
	for (i = 0; i < len; i++)
	{
		if (isdigit(text[i]) == 0)
		{
			text[k] = text[i];
			k++;
		}
	}
	text[k] = '\0'; /* THE STRING NOW ENDS AFTER THE LAST KEPT CHARACTER */

	printf("Without digits: %s\n", text);

	return 0;
}
