/* HOW MANY TIMES A CHARACTER APPEARS IN A WORD */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char word[100] = "";
	char ch = 0;
	int i;
	int count = 0;

	printf("Enter a word: ");
	scanf("%99s", word);
	printf("Character to count: ");
	scanf(" %c", &ch); /* THE SPACE SKIPS THE ENTER KEY LEFT BEHIND */

	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] == ch)
		{
			count++;
		}
	}

	printf("'%c' appears %d time(s)\n", ch, count);

	return 0;
}
