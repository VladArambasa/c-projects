/* STRINGS: AN ARRAY OF CHARACTERS THAT ENDS WITH THE TERMINATOR '\0' */
#include <stdio.h> /* PRINTF */

int main(void)
{
	char greeting[] = "Hello World!"; /* THE COMPILER ADDS THE '\0' */
	char same[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'}; /* BY HAND */

	printf("%s\n", greeting); /* PRINTS CHARACTERS UNTIL IT MEETS THE TERMINATOR */
	printf("%s\n", same);

	printf("First character: %c\n", greeting[0]); /* ONE CHARACTER, LIKE ANY ARRAY ELEMENT */

	greeting[0] = 'J'; /* SINGLE QUOTES FOR ONE CHARACTER */
	printf("%s\n", greeting);

	printf("Size of both arrays: %zu and %zu (12 characters + 1 terminator)\n",
	       sizeof(greeting), sizeof(same));

	return 0;
}
