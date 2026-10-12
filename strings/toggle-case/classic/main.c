/* TOGGLE CASE: UPPERCASE BECOMES LOWERCASE AND THE OTHER WAY AROUND */
#include <stdio.h> /* PRINTF, FGETS */

int main(void)
{
	char text[200] = "";
	int i;

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	for (i = 0; text[i] != '\0'; i++)
	{
		if (text[i] >= 'a' && text[i] <= 'z')
		{
			text[i] = text[i] - 32;
		}
		else if (text[i] >= 'A' && text[i] <= 'Z')
		{
			text[i] = text[i] + 32;
		}
	}

	printf("%s", text);

	return 0;
}
