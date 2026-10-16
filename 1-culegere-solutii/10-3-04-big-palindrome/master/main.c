/* CULEGERE X.3.4 - BIG PALINDROME
 * A VERY BIG NATURAL NUMBER OF AT MOST 50 DIGITS IS READ; CHECK WHETHER IT IS A PALINDROME
 * (IT READS THE SAME FROM LEFT TO RIGHT AND FROM RIGHT TO LEFT)
 * EXAMPLE: 12345678900987654321 -> PALINDROME; 1234567890 -> NOT A PALINDROME
 * THE NUMBER DOES NOT FIT IN ANY INTEGER TYPE, SO IT IS READ AS A STRING OF DIGITS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXLEN 51 /* 50 DIGITS AND THE END OF THE STRING */

int main(void)
{
	char s[MAXLEN] = "";
	int len, i, palindrome = 1;

	printf("The number: ");
	scanf("%50s", s);

	len = strlen(s);
	for (i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - 1 - i]) /* A DIGIT AND ITS MIRROR FROM THE OTHER END */
		{
			palindrome = 0;
		}
	}

	if (palindrome == 1)
	{
		printf("The number is a palindrome\n");
	}
	else
	{
		printf("The number is not a palindrome\n");
	}

	return 0;
}
