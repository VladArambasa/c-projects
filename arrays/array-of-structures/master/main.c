/* ARRAY OF STRUCTURES: COUNT C KEYWORDS IN THE TEXT TYPED (END THE INPUT WITH CTRL+D)
 * WORDS ARE SPLIT AT SPACES ONLY, SO A KEYWORD GLUED TO ( OR ; IS NOT COUNTED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define NKEYS 8 /* HOW MANY KEYWORDS ARE WATCHED */

struct key
{
	char word[10];
	int count;
};

int main(void)
{
	struct key table[NKEYS] = { /* EVERY ELEMENT IS A WHOLE STRUCTURE */
		{"break", 0}, {"char", 0}, {"else", 0}, {"for", 0},
		{"if", 0}, {"int", 0}, {"return", 0}, {"while", 0}
	};
	char word[50] = "";
	int i;

	while (scanf("%49s", word) == 1) /* ONE WORD AT A TIME UNTIL THE INPUT ENDS */
	{
		for (i = 0; i < NKEYS; i++)
		{
			if (strcmp(word, table[i].word) == 0)
			{
				table[i].count++; /* ELEMENT I, MEMBER COUNT */
			}
		}
	}

	for (i = 0; i < NKEYS; i++)
	{
		printf("%-7s %d\n", table[i].word, table[i].count);
	}

	return 0;
}
