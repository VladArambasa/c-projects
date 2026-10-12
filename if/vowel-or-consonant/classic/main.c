/* VOWEL OR CONSONANT */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char ch = 0;

	printf("Enter a letter: ");
	scanf(" %c", &ch); /* THE SPACE SKIPS ANY WHITESPACE BEFORE THE LETTER */

	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
	    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	{
		printf("Vowel\n");
	}
	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		printf("Consonant\n");
	}
	else
	{
		printf("Not a letter\n");
	}

	return 0;
}
