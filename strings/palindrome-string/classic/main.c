/* PALINDROME STRING: IT READS THE SAME FROM BOTH ENDS (LEVEL, RADAR) */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

int main(void)
{
	char word[100] = "";
	int start, end;
	int palindrome = 1;

	printf("Enter a word: ");
	scanf("%99s", word);

	start = 0;
	end = strlen(word) - 1;
	while (start < end)
	{
		if (word[start] != word[end])
		{
			palindrome = 0;
			break; /* ONE DIFFERENCE IS ENOUGH */
		}
		start++;
		end--;
	}

	if (palindrome)
	{
		printf("%s is a palindrome\n", word);
	}
	else
	{
		printf("%s is not a palindrome\n", word);
	}

	return 0;
}
