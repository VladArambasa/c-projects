/* LENGTH OF A STRING WITHOUT STRLEN: COUNT UNTIL THE TERMINATOR */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char text[100] = "";
	int length = 0;

	printf("Enter a text: ");
	fgets(text, sizeof(text), stdin);

	while (text[length] != '\0' && text[length] != '\n') /* STOP AT THE END OR AT THE ENTER KEY */
	{
		length++;
	}

	printf("Length = %d\n", length);

	return 0;
}
