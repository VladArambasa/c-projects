/* CULEGERE XIII.2.23 - THREE DIVISORS CODE
 * N IS READ (N <= 15). THE FIRST N SMALL LETTERS ARE CODED WITH THE SMALLEST N NATURAL NUMBERS THAT
 * HAVE EXACTLY 3 DIVISORS: A GETS THE SMALLEST ONE, B THE NEXT ONE, AND SO ON.
 * A) PRINT THE N NUMBERS  B) READ A TEXT OF AT MOST 20 LETTERS AND PRINT ITS CODE
 * EXAMPLE: N = 2, AABBAA -> A) 4 9  B) 449944
 * ASSUMPTION: THE TEXT IS ONE WORD MADE OF THE FIRST N SMALL LETTERS; OTHER CHARACTERS GET NO CODE
 * METHOD: COUNT THE DIVISORS OF 1, 2, 3, ... */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXN 15

/* HOW MANY DIVISORS N HAS: TRY EVERY NUMBER FROM 1 TO N */
int count_divisors(int n)
{
	int d, count = 0;

	for (d = 1; d <= n; d++)
	{
		if (n % d == 0)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	int code[MAXN];
	char text[21] = "";
	int n = 0, found = 0, m = 0, i, len;

	printf("n = ");
	scanf("%d", &n);

	/* A) TEST THE NUMBERS 1, 2, 3, ... UNTIL N OF THEM HAVE EXACTLY 3 DIVISORS */
	while (found < n)
	{
		m++;
		if (count_divisors(m) == 3)
		{
			code[found] = m;
			found++;
		}
	}
	printf("a)");
	for (i = 0; i < n; i++)
	{
		printf(" %d", code[i]);
	}
	printf("\n");

	/* B) EVERY LETTER IS REPLACED BY ITS NUMBER: A BY CODE[0], B BY CODE[1] ... */
	printf("Text: ");
	scanf("%20s", text);
	len = strlen(text);
	printf("b) ");
	for (i = 0; i < len; i++)
	{
		if (text[i] >= 'a' && text[i] < 'a' + n) /* ONLY THE FIRST N LETTERS HAVE A CODE */
		{
			printf("%d", code[text[i] - 'a']);
		}
	}
	printf("\n");
	return 0;
}
