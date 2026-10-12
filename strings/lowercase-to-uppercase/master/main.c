/* LOWERCASE TO UPPERCASE WITHOUT LIBRARY FUNCTIONS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

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
			text[i] = text[i] - 32; /* LOWERCASE CODES ARE 32 MORE THAN UPPERCASE ONES */
		}
	}

	printf("%s", text);

	return 0;
}
