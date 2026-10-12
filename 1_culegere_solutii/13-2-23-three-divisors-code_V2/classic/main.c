/* CULEGERE XIII.2.23 - THREE DIVISORS CODE
 * N IS READ (N <= 15). THE FIRST N SMALL LETTERS ARE CODED WITH THE SMALLEST N NATURAL NUMBERS THAT
 * HAVE EXACTLY 3 DIVISORS: A GETS THE SMALLEST ONE, B THE NEXT ONE, AND SO ON.
 * A) PRINT THE N NUMBERS  B) READ A TEXT OF AT MOST 20 LETTERS AND PRINT ITS CODE
 * EXAMPLE: N = 2, AABBAA -> A) 4 9  B) 449944
 * ASSUMPTION: THE TEXT IS ONE WORD MADE OF THE FIRST N SMALL LETTERS; OTHER CHARACTERS GET NO CODE
 * IMPROVEMENT: ONLY SQUARES OF PRIMES HAVE EXACTLY 3 DIVISORS (1, P, P*P): SQUARE THE PRIMES */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRLEN */

#define MAXN 15

/* 1 IF N IS PRIME (DIVISORS ARE TRIED ONLY UP TO THE SQUARE ROOT OF N) */
int is_prime(int n)
{
	int d;

	if (n < 2)
	{
		return 0;
	}
	for (d = 2; d * d <= n; d++)
	{
		if (n % d == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int code[MAXN];
	char text[21] = "";
	int n = 0, found = 0, p = 1, i, len;

	printf("n = ");
	scanf("%d", &n);

	/* A) THE SQUARES OF THE PRIMES 2, 3, 5, 7, ... ARE 4, 9, 25, 49, ... */
	while (found < n)
	{
		p++;
		if (is_prime(p) == 1)
		{
			code[found] = p * p;
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
