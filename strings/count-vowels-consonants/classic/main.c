/* COUNT THE VOWELS AND THE CONSONANTS IN A TEXT */
#include <stdio.h> /* PRINTF, FGETS */

int main(void)
{
	char text[200] = "";
	int i;
	int vowels = 0, consonants = 0;

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	for (i = 0; text[i] != '\0'; i++)
	{
		char ch = text[i];

		if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + 32; /* UPPERCASE TO LOWERCASE: THE CODES DIFFER BY 32 */
		}
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			vowels++;
		}
		else if (ch >= 'a' && ch <= 'z') /* ANY OTHER LETTER */
		{
			consonants++;
		}
	}

	printf("Vowels = %d, Consonants = %d\n", vowels, consonants);

	return 0;
}
