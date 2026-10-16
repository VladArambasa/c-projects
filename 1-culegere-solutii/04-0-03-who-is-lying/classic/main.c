/* CULEGERE IV.3 - WHO IS LYING?
 * A SAYS THAT B LIES, B SAYS THAT C LIES, C SAYS THAT A AND B BOTH LIE.
 * WHO LIES AND WHO TELLS THE TRUTH?
 * IDEA: A, B, C ARE BOOLEAN (1 = TELLS THE TRUTH). WHAT AN HONEST PERSON SAYS IS TRUE AND WHAT
 * A LIAR SAYS IS FALSE, SO EVERY STATEMENT HAS THE SAME VALUE AS ITS AUTHOR. ALL 8 COMBINATIONS
 * ARE TRIED AND THE ONES THAT FIT ARE PRINTED
 * RESULT: A LIES, B TELLS THE TRUTH, C LIES */
#include <stdio.h> /* PRINTF */

/* PRINTS WHETHER ONE PERSON LIES OR TELLS THE TRUTH */
void print_person(char name, int truth)
{
	if (truth == 1)
	{
		printf("%c tells the truth", name);
	}
	else
	{
		printf("%c lies", name);
	}
}

int main(void)
{
	int a, b, c;    /* 1 = TELLS THE TRUTH, 0 = LIES */
	int sa, sb, sc; /* THE VALUE OF WHAT EACH ONE SAYS */
	int solutions = 0;

	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				sa = !b;       /* A SAYS: "B LIES" */
				sb = !c;       /* B SAYS: "C LIES" */
				sc = !a && !b; /* C SAYS: "A AND B LIE" */
				/* AN HONEST PERSON SAYS SOMETHING TRUE, A LIAR SOMETHING FALSE */
				if (sa == a && sb == b && sc == c)
				{
					print_person('a', a);
					printf(", ");
					print_person('b', b);
					printf(", ");
					print_person('c', c);
					printf("\n");
					solutions++;
				}
			}
		}
	}

	if (solutions == 0)
	{
		printf("No solution\n");
	}

	return 0;
}
