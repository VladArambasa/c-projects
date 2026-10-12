/* REPLACE EVERY SPACE WITH A HYPHEN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char text[200] = "";
	int i;

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	for (i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == ' ')
		{
			text[i] = '-';
		}
	}

	printf("%s", text);

	return 0;
}
