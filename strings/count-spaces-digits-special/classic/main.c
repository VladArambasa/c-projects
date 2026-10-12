/* COUNT THE SPACES, DIGITS AND SPECIAL CHARACTERS IN A TEXT (LETTERS ARE NOT COUNTED) */
#include <stdio.h> /* PRINTF, FGETS */

int main(void)
{
	char text[200] = "";
	int i;
	int spaces = 0, digits = 0, special = 0;

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	for (i = 0; text[i] != '\0' && text[i] != '\n'; i++)
	{
		char ch = text[i];

		if (ch == ' ')
		{
			spaces++;
		}
		else if (ch >= '0' && ch <= '9')
		{
			digits++;
		}
		else if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) /* NOT A LETTER */
		{
			special++;
		}
	}

	printf("Spaces = %d, Digits = %d, Special = %d\n", spaces, digits, special);

	return 0;
}
