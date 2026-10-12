/* COPY A STRING (V3): THE CLASSIC ONE-LINE LOOP, THE TERMINATOR IS COPIED BY THE LOOP ITSELF */
#include <stdio.h> /* PRINTF */

void copy_string(char *s, char *t) /* COPY T INTO S */
{
	while ((*s++ = *t++) != '\0') /* COPY, ADVANCE BOTH, STOP AFTER COPYING '\0' */
	{
		;
	}
}

int main(void)
{
	char source[] = "Timisoara";
	char destination[20];

	copy_string(destination, source);
	printf("Copied: %s\n", destination);

	return 0;
}
