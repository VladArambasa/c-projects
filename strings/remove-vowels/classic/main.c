/* REMOVE ALL THE VOWELS FROM A TEXT */
#include <stdio.h> /* PRINTF, FGETS */

int main(void)
{
	char text[200] = "", result[200];
	int i, j = 0; /* I READS FROM TEXT, J WRITES INTO RESULT */

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	for (i = 0; text[i] != '\0'; i++)
	{
		char ch = text[i];

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
		      ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'))
		{
			result[j] = ch; /* KEEP EVERYTHING THAT IS NOT A VOWEL */
			j++;
		}
	}
	result[j] = '\0';

	printf("%s", result);

	return 0;
}
