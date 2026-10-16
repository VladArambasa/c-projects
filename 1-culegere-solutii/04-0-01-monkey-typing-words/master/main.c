/* CULEGERE IV.1 - THE TYPING MONKEY
 * CATALINA'S MONKEY MUST LEARN TO TYPE THREE WORDS OF AT MOST 10 CHARACTERS. READ THE THREE
 * WORDS, THEN THE WORDS TYPED BY THE MONKEY, ONE PER LINE. STOP AS SOON AS THE MONKEY HAS TYPED
 * EACH OF THE THREE WORDS CORRECTLY (IN ANY ORDER, AFTER ANY NUMBER OF WRONG WORDS) AND PRINT
 * "YOU DID IT!"
 * EXAMPLE: WORDS PALAT CALCULATOR JUNGLA, TYPED: PALAT CALUTIN JUNGLA PIALAT CUCALATOR CALCULATOR
 *          PALAT -> YOU DID IT! (THE FIRST PALAT IS TYPED WITH A SMALL P, SO IT DOES NOT COUNT)
 * ASSUMPTION: CAPITAL AND SMALL LETTERS ARE DIFFERENT, SO A WORD IN THE WRONG CASE IS WRONG */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char word1[11] = "", word2[11] = "", word3[11] = ""; /* THE THREE WORDS TO LEARN */
	char typed[51] = "";                    /* ONE WORD TYPED BY THE MONKEY */
	int found1 = 0, found2 = 0, found3 = 0; /* BOOLEAN: 1 = THAT WORD WAS TYPED CORRECTLY */
	int all = 0;                            /* BOOLEAN: 1 = ALL THREE WORDS WERE TYPED */

	printf("The three words: ");
	scanf("%10s %10s %10s", word1, word2, word3);

	printf("Words typed by the monkey: ");
	while (all == 0 && scanf("%50s", typed) == 1) /* THE LOOP ALSO STOPS IF THE INPUT ENDS */
	{
		if (strcmp(typed, word1) == 0) /* STRCMP GIVES 0 FOR EQUAL WORDS */
		{
			found1 = 1;
		}
		if (strcmp(typed, word2) == 0)
		{
			found2 = 1;
		}
		if (strcmp(typed, word3) == 0)
		{
			found3 = 1;
		}
		all = found1 && found2 && found3; /* TRUE ONLY WHEN ALL THREE ARE TRUE */
	}

	if (all == 1)
	{
		printf("YOU DID IT!\n");
	}

	return 0;
}
