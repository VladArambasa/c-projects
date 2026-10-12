/* PATTERN: GROUPS OF 1, 3, 5, 3 AND 1 STARS, ONE STAR PER LINE, A BLANK LINE BETWEEN GROUPS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int groups[5] = {1, 3, 5, 3, 1}; /* HOW MANY STARS IN EACH GROUP */
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < groups[i]; j++)
		{
			printf("*\n");
		}
		if (i < 4) /* NO BLANK LINE AFTER THE LAST GROUP */
		{
			printf("\n");
		}
	}

	return 0;
}
