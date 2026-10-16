/* CULEGERE XIII.3.6 - NUMBER LINES WITH COMMANDS
 * EVERY LINE OF NUMERE.IN (AT MOST 10 LINES) HOLDS AT LEAST TWO NATURAL NUMBERS (AT MOST 10
 * NUMBERS, EACH AT MOST 64000) AND THEN ONE SMALL LETTER: P - HOW MANY OF THE NUMBERS ARE PRIME;
 * M - THE AVERAGE OF THE NUMBERS WITH TWO DECIMALS; N - HOW MANY PRIMES LIE IN THE CLOSED
 * INTERVAL GIVEN BY THE TWO NUMBERS; I - THE INVERSE (1 / X) OF EVERY NUMBER WITH TWO DECIMALS.
 * FOR EVERY LINE OF NUMERE.IN WRITE ONE LINE WITH THE RESULT IN NUMERE.OUT
 * EXAMPLE: 13 21 27 29 P -> 2; 12 5 I -> 0.08 0.20 (THE BOOK WRITES 0,08 0,20) */
#include <stdio.h>  /* PRINTF, FOPEN, FSCANF, FPRINTF */
#include <stdlib.h> /* ATOI */

#define MAXNUM 10

/* 1 IF X IS PRIME (THE DIVISORS ARE TRIED UP TO THE SQUARE ROOT OF X) */
int is_prime(int x)
{
	int d;

	if (x < 2)
	{
		return 0;
	}
	for (d = 2; d * d <= x; d++)
	{
		if (x % d == 0)
		{
			return 0;
		}
	}
	return 1;
}

/* HOW MANY PRIMES LIE BETWEEN A AND B, BOTH INCLUDED (A AND B IN ANY ORDER) */
int primes_between(int a, int b)
{
	int x, temp, count = 0;

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	for (x = a; x <= b; x++)
	{
		if (is_prime(x) == 1)
		{
			count++;
		}
	}
	return count;
}

/* WRITES THE RESULT OF ONE LINE, GIVEN ITS NUMBERS AND ITS COMMAND LETTER */
void solve_line(FILE *out, int number[], int count, char command)
{
	int i, primes;
	double sum;

	if (command == 'p')
	{
		primes = 0;
		for (i = 0; i < count; i++)
		{
			if (is_prime(number[i]) == 1)
			{
				primes++;
			}
		}
		fprintf(out, "%d\n", primes);
	}
	else if (command == 'm')
	{
		sum = 0;
		for (i = 0; i < count; i++)
		{
			sum = sum + number[i];
		}
		fprintf(out, "%.2f\n", sum / count);
	}
	else if (command == 'n')
	{
		fprintf(out, "%d\n", primes_between(number[0], number[1]));
	}
	else if (command == 'i')
	{
		for (i = 0; i < count; i++)
		{
			if (i > 0)
			{
				fprintf(out, " ");
			}
			fprintf(out, "%.2f", 1.0 / number[i]);
		}
		fprintf(out, "\n");
	}
}

int main(void)
{
	FILE *in = fopen("NUMERE.IN", "r");
	FILE *out;
	char word[20] = "";
	int number[MAXNUM];
	int count = 0;

	if (in == NULL)
	{
		printf("Cannot open NUMERE.IN\n");
		return 1;
	}
	out = fopen("NUMERE.OUT", "w");

	/* THE FILE IS READ WORD BY WORD: THE NUMBERS ARE KEPT UNTIL A LETTER ENDS THE LINE */
	while (fscanf(in, "%19s", word) == 1)
	{
		if (word[0] >= '0' && word[0] <= '9')
		{
			number[count] = atoi(word);
			count++;
		}
		else
		{
			solve_line(out, number, count, word[0]);
			count = 0;
		}
	}
	fclose(in);
	fclose(out);

	return 0;
}
