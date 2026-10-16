/* CULEGERE IV.2 - WHO WATCHES TV?
 * ANA, BARBU, CALIN, DUMITRU AND ELENA SPEND A WINTER DAY TOGETHER. WE KNOW THAT:
 * - IF ANA WATCHES TV, SO DOES BARBU
 * - DUMITRU OR ELENA OR BOTH WATCH TV
 * - BARBU OR CALIN WATCHES TV, BUT NOT BOTH
 * - DUMITRU AND CALIN EITHER BOTH WATCH TV OR BOTH DO NOT
 * - IF ELENA WATCHES TV, THEN ANA AND DUMITRU WATCH TOO
 * WHO WATCHES TV? THE BOOLEAN VARIABLES A, B, C, D, E ARE 1 (TRUE) WHEN THAT PERSON WATCHES TV.
 * ALL 32 COMBINATIONS ARE TRIED; THOSE THAT MAKE ALL FIVE STATEMENTS TRUE ARE PRINTED
 * RESULT: A=0 B=0 C=1 D=1 E=0 -> CALIN AND DUMITRU WATCH TV */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* RETURNS 1 WHEN ALL FIVE STATEMENTS ARE TRUE FOR THIS COMBINATION */
int all_true(int a, int b, int c, int d, int e)
{
	int s1, s2, s3, s4, s5;

	s1 = !a || b;        /* "IF A THEN B" IS FALSE ONLY WHEN A IS TRUE AND B IS FALSE */
	s2 = d || e;         /* DUMITRU OR ELENA OR BOTH */
	s3 = b != c;         /* EXACTLY ONE OF BARBU AND CALIN */
	s4 = d == c;         /* DUMITRU AND CALIN ONLY TOGETHER */
	s5 = !e || (a && d); /* IF ELENA, THEN ANA AND DUMITRU */

	return s1 && s2 && s3 && s4 && s5;
}

/* PRINTS ONE SOLUTION: THE VALUES AND THE NAMES OF THOSE WHO WATCH TV */
void print_solution(int a, int b, int c, int d, int e)
{
	printf("a=%d b=%d c=%d d=%d e=%d -> watching TV:", a, b, c, d, e);
	if (a == 1)
	{
		printf(" Ana");
	}
	if (b == 1)
	{
		printf(" Barbu");
	}
	if (c == 1)
	{
		printf(" Calin");
	}
	if (d == 1)
	{
		printf(" Dumitru");
	}
	if (e == 1)
	{
		printf(" Elena");
	}
	printf("\n");
}

int main(void)
{
	int a, b, c, d, e;
	int solutions = 0;

	/* EVERY PERSON GETS THE VALUE 0 (FALSE) AND THEN 1 (TRUE) */
	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				for (d = 0; d <= 1; d++)
				{
					for (e = 0; e <= 1; e++)
					{
						if (all_true(a, b, c, d, e) == 1)
						{
							print_solution(a, b, c, d, e);
							solutions++;
						}
					}
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
