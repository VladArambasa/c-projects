/* REVERSE A STRING (V2): SWAP THE FIRST AND THE LAST CHARACTER, MOVING INWARD, IN PLACE */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

int main(void)
{
	char text[100] = "";
	char temp;
	int start, end;

	printf("Enter a word: ");
	scanf("%99s", text);

	start = 0;
	end = strlen(text) - 1;
	while (start < end) /* THE TWO INDEXES MEET IN THE MIDDLE */
	{
		temp = text[start];
		text[start] = text[end];
		text[end] = temp;
		start++;
		end--;
	}

	printf("Reversed: %s\n", text);

	return 0;
}
