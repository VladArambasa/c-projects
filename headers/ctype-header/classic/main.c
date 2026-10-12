/* CTYPE.H: CLASSIFY AND CONVERT CHARACTERS */
#include <stdio.h> /* PRINTF, FGETS */
#include <ctype.h> /* ISALPHA, ISDIGIT, ISSPACE, ISPUNCT, ISUPPER, TOUPPER */

int main(void)
{
	char text[200] = "";
	int i;
	int letters = 0, digits = 0, spaces = 0, punctuation = 0, uppercase = 0;

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	for (i = 0; text[i] != '\0' && text[i] != '\n'; i++) /* STOP BEFORE THE ENTER KEY */
	{
		unsigned char c = text[i]; /* CTYPE FUNCTIONS EXPECT AN UNSIGNED CHAR VALUE */

		if (isalpha(c))
		{
			letters++;
		}
		if (isupper(c))
		{
			uppercase++;
		}
		if (isdigit(c))
		{
			digits++;
		}
		if (isspace(c)) /* SPACE, TAB, NEWLINE */
		{
			spaces++;
		}
		if (ispunct(c))
		{
			punctuation++;
		}
		text[i] = toupper(c); /* CONVERT WHILE WE ARE HERE */
	}

	printf("letters = %d (uppercase %d), digits = %d, spaces = %d, punctuation = %d\n",
	       letters, uppercase, digits, spaces, punctuation);
	printf("In capitals: %s", text);

	return 0;
}
