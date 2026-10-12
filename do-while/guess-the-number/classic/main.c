/* GUESS THE NUMBER: THE COMPUTER PICKS 1 TO 100, YOU GUESS UNTIL YOU FIND IT */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* RAND, SRAND */
#include <time.h>   /* TIME */

int main(void)
{
	int secret, guess = 0;
	int tries = 0;

	srand(time(NULL));         /* A DIFFERENT START FOR RAND AT EVERY RUN */
	secret = rand() % 100 + 1; /* 0..99 SHIFTED TO 1..100 */

	do
	{
		printf("Your guess: ");
		if (scanf("%d", &guess) != 1)
		{
			printf("\nGiving up? The number was %d\n", secret);
			return 1;
		}
		tries++;

		if (guess < secret)
		{
			printf("Higher!\n");
		}
		else if (guess > secret)
		{
			printf("Lower!\n");
		}
	} while (guess != secret);

	printf("Correct! Number of tries: %d\n", tries);

	return 0;
}
