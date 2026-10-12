/* COPY A STRING WITH ARRAY INDEXES, LIKE STRCPY */
#include <stdio.h> /* PRINTF */

void copy_string(char s[], char t[]) /* COPY T INTO S */
{
	int i = 0;

	while (t[i] != '\0')
	{
		s[i] = t[i];
		i++;
	}
	s[i] = '\0'; /* COPY THE TERMINATOR TOO */
}

int main(void)
{
	char source[] = "Timisoara";
	char destination[20]; /* MUST BE BIG ENOUGH FOR THE SOURCE */

	copy_string(destination, source);
	printf("Copied: %s\n", destination);

	return 0;
}
