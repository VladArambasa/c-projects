/* CULEGERE VI.1.3 - LETTERS IN REVERSE ORDER
 * READ 10 LETTERS AND PRINT THEM IN THE REVERSE ORDER OF READING
 * EXAMPLE: A B R A C A D A B R -> R B A D A C A R B A */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define N 10 /* HOW MANY LETTERS */

int main(void)
{
	char letters[N] = {0};
	int i;

	printf("The %d letters: ", N);
	for (i = 0; i < N; i++)
	{
		scanf(" %c", &letters[i]); /* THE SPACE BEFORE %C SKIPS SPACES AND ENTERS */
	}

	for (i = N - 1; i >= 0; i--) /* FROM THE LAST LETTER BACK TO THE FIRST ONE */
	{
		printf("%c ", letters[i]);
	}
	printf("\n");

	return 0;
}
