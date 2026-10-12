/* PRINT EACH CHARACTER OF A STRING ON ITS OWN LINE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char word[100] = "";
	int i;

	printf("Enter a word: ");
	scanf("%99s", word);

	for (i = 0; word[i] != '\0'; i++) /* UNTIL THE TERMINATOR */
	{
		printf("%c\n", word[i]);
	}

	return 0;
}
