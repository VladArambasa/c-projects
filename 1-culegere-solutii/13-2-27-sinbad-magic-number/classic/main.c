/* CULEGERE XIII.2.27 - SINBAD'S MAGIC NUMBER
 * N IS READ (THE NUMBER OF SPIRITS DEFEATED BY SINBAD). PRINT THE SMALLEST NUMBER WHOSE FIRST DIGIT
 * AND WHOSE NUMBER OF DIGITS ARE BOTH EQUAL TO N, IN WHICH EVERY TWO NEIGHBOURING DIGITS FORM A
 * PRIME NUMBER, ALL THESE PRIMES BEING DIFFERENT; IF THERE IS NO SUCH NUMBER PRINT DOES NOT EXIST
 * EXAMPLE: N = 3 -> 311 (31 AND 11 ARE DIFFERENT PRIMES)
 * ASSUMPTION: FOR N = 1 THE ANSWER IS 1 (A ONE-DIGIT NUMBER HAS NO NEIGHBOURING DIGITS TO CHECK) */
#include <stdio.h> /* PRINTF, SCANF */

int n;
int digit[9];  /* THE DIGITS OF THE NUMBER BEING BUILT */
int used[100]; /* USED[P] = 1 IF THE PRIME P IS ALREADY MADE BY TWO NEIGHBOURING DIGITS */
int found;

/* 1 IF X IS PRIME, 0 OTHERWISE */
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

/* CHOOSES THE DIGIT ON POSITION POS, THE SMALLEST ONE FIRST (BACKTRACKING) */
void choose(int pos)
{
	int d, pair;

	if (pos == n)
	{
		/* ALL N DIGITS ARE CHOSEN; SMALL DIGITS ARE TRIED FIRST, SO IT IS THE SMALLEST */
		found = 1;
		return;
	}
	for (d = 0; d <= 9 && found == 0; d++)
	{
		pair = digit[pos - 1] * 10 + d; /* MADE WITH THE PREVIOUS DIGIT */
		if (is_prime(pair) == 1 && used[pair] == 0)
		{
			used[pair] = 1;
			digit[pos] = d;
			choose(pos + 1);
			used[pair] = 0; /* FREE THE PRIME AGAIN FOR THE NEXT TRIES */
		}
	}
}

int main(void)
{
	int i;

	printf("n = ");
	scanf("%d", &n);

	found = 0;
	if (n >= 1 && n <= 9) /* THE FIRST DIGIT IS N, SO N MUST BE A DIGIT FROM 1 TO 9 */
	{
		digit[0] = n;
		choose(1);
	}

	if (found == 1)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d", digit[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Does not exist\n");
	}
	return 0;
}
