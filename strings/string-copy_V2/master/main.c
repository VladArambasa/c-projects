/* COPY A STRING (V2): WALK WITH POINTERS INSTEAD OF COMPUTING S[I] AND T[I] EVERY TIME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

void copy_string(char *s, char *t) /* COPY T INTO S */
{
	while (*t != '\0')
	{
		*s = *t; /* COPY ONE CHARACTER */
		s++;     /* MOVE BOTH POINTERS TO THE NEXT CHARACTER */
		t++;
	}
	*s = '\0';
}

int main(void)
{
	char source[] = "Timisoara";
	char destination[20];

	copy_string(destination, source);
	printf("Copied: %s\n", destination);

	return 0;
}
