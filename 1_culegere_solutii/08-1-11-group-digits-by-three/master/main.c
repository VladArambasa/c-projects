/* CULEGERE VIII.1.11 - DIGITS IN GROUPS OF THREE
 * A NUMBER WITH MORE THAN 10 DIGITS IS READ AS A STRING; PRINT IT WITH THE DIGITS GROUPED BY
 * THREE FROM RIGHT TO LEFT, THE GROUPS BEING SEPARATED BY A DOT
 * EXAMPLE: 12345678900 -> 12.345.678.900 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX_LEN 257 /* 255 CHARACTERS, THE NEWLINE AND THE NULL CHARACTER */

/* READS A WHOLE LINE INTO S AND REMOVES THE NEWLINE FROM ITS END */
void read_line(char s[], int size)
{
	int len;

	if (fgets(s, size, stdin) == NULL)
	{
		s[0] = '\0'; /* NOTHING WAS READ: THE TEXT STAYS EMPTY */
	}
	len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
	}
}

int main(void)
{
	char number[MAX_LEN];
	int i, len;

	printf("Number: ");
	read_line(number, MAX_LEN);
	len = strlen(number);

	printf("Grouped: ");
	for (i = 0; i < len; i++)
	{
		printf("%c", number[i]);
		/* AFTER THIS DIGIT THERE ARE LEN - 1 - I DIGITS LEFT;
		 * A DOT GOES HERE WHEN THEY FORM COMPLETE GROUPS OF THREE */
		if (i < len - 1 && (len - 1 - i) % 3 == 0)
		{
			printf(".");
		}
	}
	printf("\n");

	return 0;
}
