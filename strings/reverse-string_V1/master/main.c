/* REVERSE A STRING: COPY IT BACKWARDS INTO A SECOND STRING */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char text[100] = "", reversed[100];
	int i, length;

	printf("Enter a word: ");
	scanf("%99s", text);

	length = strlen(text);
	for (i = 0; i < length; i++)
	{
		reversed[i] = text[length - 1 - i]; /* FIRST GETS THE LAST */
	}
	reversed[length] = '\0'; /* EVERY STRING NEEDS ITS TERMINATOR */

	printf("Reversed: %s\n", reversed);

	return 0;
}
