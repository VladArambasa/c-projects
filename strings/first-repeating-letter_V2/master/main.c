/* FIRST REPEATING LOWERCASE LETTER (V2): ONE PASS WITH A TABLE THAT REMEMBERS THE LETTERS SEEN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char word[100] = "";
	int seen[26] = {0}; /* SEEN[0] FOR A, SEEN[1] FOR B, ... */
	int i;

	printf("Enter a word: ");
	scanf("%99s", word);

	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
		{
			int index = word[i] - 'a'; /* LETTER TO TABLE POSITION */

			if (seen[index])
			{
				printf("First repeating letter: %c\n", word[i]);
				return 0;
			}
			seen[index] = 1;
		}
	}

	printf("No repeating letter found\n");

	return 0;
}
