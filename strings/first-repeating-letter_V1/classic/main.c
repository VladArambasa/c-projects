/* FIRST REPEATING LOWERCASE LETTER: FOR EACH LETTER, LOOK BACK FOR AN EARLIER COPY */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char word[100] = "";
	int i, j;

	printf("Enter a word: ");
	scanf("%99s", word);

	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] < 'a' || word[i] > 'z')
		{
			continue; /* ONLY LOWERCASE LETTERS COUNT */
		}
		for (j = 0; j < i; j++) /* DID THIS LETTER APPEAR BEFORE POSITION I? */
		{
			if (word[j] == word[i])
			{
				printf("First repeating letter: %c\n", word[i]);
				return 0;
			}
		}
	}

	printf("No repeating letter found\n");

	return 0;
}
