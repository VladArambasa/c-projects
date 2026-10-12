/* CULEGERE III.9.7 - ROMAN NUMERALS
 * A NATURAL NUMBER IS READ; PRINT IT IN ROMAN NUMERALS
 * ASSUMPTION: 1 <= N <= 3999 (THERE IS NO ROMAN ZERO, AND 4000 OR MORE NEEDS SPECIAL SIGNS);
 * FOR ANY OTHER NUMBER THE PROGRAM PRINTS NOT POSSIBLE
 * EXAMPLES: 1994 -> MCMXCIV; 2026 -> MMXXVI; 4 -> IV */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	/* EVERY VALUE WITH ITS LETTERS, FROM THE LARGEST DOWN; 900, 400, 90, 40, 9 AND 4
	 * ARE WRITTEN WITH A SMALLER LETTER IN FRONT OF A LARGER ONE (CM = 1000 - 100) */
	int value[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char letters[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L",
	                       "XL", "X", "IX", "V", "IV", "I"};
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);

	if (n < 1 || n > 3999)
	{
		printf("Not possible\n");
		return 0;
	}

	for (i = 0; i < 13; i++)
	{
		while (n >= value[i]) /* THE LARGEST VALUE THAT STILL FITS, AS OFTEN AS IT FITS */
		{
			printf("%s", letters[i]);
			n = n - value[i];
		}
	}
	printf("\n");

	return 0;
}
