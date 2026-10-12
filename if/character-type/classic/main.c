/* CHARACTER TYPE: UPPERCASE, LOWERCASE, DIGIT OR SPECIAL CHARACTER */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char ch = 0;

	printf("Enter a character: ");
	scanf(" %c", &ch);

	if (ch >= 'A' && ch <= 'Z') /* LETTERS AND DIGITS HAVE CONSECUTIVE CODES */
	{
		printf("Uppercase letter\n");
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		printf("Lowercase letter\n");
	}
	else if (ch >= '0' && ch <= '9')
	{
		printf("Digit\n");
	}
	else
	{
		printf("Special character\n");
	}

	return 0;
}
