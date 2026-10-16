/* CULEGERE II.4.7 - VOWEL OR CONSONANT
 * READ A LETTER AND PRINT WHETHER IT IS A VOWEL OR A CONSONANT
 * EXAMPLE: A -> VOWEL
 * ASSUMPTION: THE VOWELS ARE A, E, I, O, U, SMALL OR CAPITAL */
#include <stdio.h> /* PRINTF, SCANF */
#include <ctype.h> /* TOLOWER */

int main(void)
{
	char c = ' ';

	printf("Letter: ");
	scanf(" %c", &c);

	c = tolower(c); /* A CAPITAL LETTER BECOMES SMALL, SO ONLY 5 TESTS ARE NEEDED */

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		printf("vowel\n");
	}
	else
	{
		printf("consonant\n");
	}

	return 0;
}
