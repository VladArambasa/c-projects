/* CULEGERE XIII.4.2 - OCTAL NUMBER CODE
 * THE BOOK GIVES THE CODES 0 -> 0, 1 -> 143, 2 -> 307, 3 -> 453, 7 -> 1273, 10 -> 1747, 11 -> 2113,
 * 576 -> 160377. THE RULE BEHIND THEM: THE CODE OF N IS THE NUMBER 100 * N - 1 WRITTEN IN BASE 8
 * (1 -> 99, AND 99 = 1 * 64 + 4 * 8 + 3 IS 143 IN BASE 8), AND THE CODE OF 0 IS 0. CNI.IN HOLDS
 * NATURAL NUMBERS, ONE PER LINE; WRITE THEIR CODES IN CNI.OUT, ONE PER LINE
 * ASSUMPTION: THE RULE IS DEDUCED FROM THE TABLE, WHICH IS ALL THAT THE STATEMENT GIVES
 * EXAMPLE: 10 / 0 / 7 -> 1747 / 0 / 1273 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* THE BASE 8 DIGITS OF VALUE, READ AS A BASE 10 NUMBER (99 -> 143) */
long long to_base8(long long value)
{
	long long result = 0, place = 1;

	while (value > 0)
	{
		result = result + (value % 8) * place; /* THE NEXT DIGIT, FROM THE UNITS UP */
		place = place * 10;
		value = value / 8;
	}
	return result;
}

/* THE CODE OF A NATURAL NUMBER */
long long code(long long n)
{
	if (n == 0)
	{
		return 0;
	}
	return to_base8(100 * n - 1);
}

int main(void)
{
	FILE *in = fopen("CNI.IN", "r");
	FILE *out;
	long long n = 0;

	if (in == NULL)
	{
		printf("Cannot open CNI.IN\n");
		return 1;
	}
	out = fopen("CNI.OUT", "w");
	while (fscanf(in, "%lld", &n) == 1)
	{
		fprintf(out, "%lld\n", code(n));
	}
	fclose(in);
	fclose(out);

	return 0;
}
