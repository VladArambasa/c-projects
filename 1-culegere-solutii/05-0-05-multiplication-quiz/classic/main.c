/* CULEGERE V.5 - MULTIPLICATION TEST
 * THE COMPUTER CHOOSES TWO NUMBERS FROM 0 TO 10 AND ASKS FOR THEIR PRODUCT; THE PUPIL HAS AT
 * MOST 5 ATTEMPTS TO GIVE THE RIGHT ANSWER
 * EXAMPLE: 7 * 8 = 54 -> WRONG!, 7 * 8 = 56 -> CORRECT! (THE NUMBERS ARE RANDOM)
 * ASSUMPTION: ONE QUESTION WITH AT MOST 5 ATTEMPTS; THE TEST STOPS AT THE FIRST RIGHT ANSWER */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* RAND, SRAND */
#include <time.h>   /* TIME */

int main(void)
{
	int a, b;
	int answer = 0, attempt = 0;
	int correct = 0; /* BOOLEAN: 1 AFTER THE RIGHT ANSWER */

	srand(time(NULL)); /* DIFFERENT NUMBERS AT EVERY RUN */
	a = rand() % 11;   /* FROM 0 TO 10 */
	b = rand() % 11;

	while (attempt < 5 && correct == 0) /* AT MOST 5 ATTEMPTS, FEWER IF THE ANSWER IS RIGHT */
	{
		attempt++;
		printf("Attempt %d: %d * %d = ", attempt, a, b);
		scanf("%d", &answer);
		if (answer == a * b)
		{
			printf("Correct!\n");
			correct = 1;
		}
		else
		{
			printf("Wrong!\n");
		}
	}

	if (correct == 0)
	{
		printf("No attempts left. The correct answer was %d * %d = %d\n", a, b, a * b);
	}

	return 0;
}
