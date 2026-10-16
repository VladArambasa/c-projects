/* CULEGERE X.3.3 - PRODUCT OF TWO BIG NUMBERS
 * TWO NATURAL NUMBERS OF AT MOST 25 DIGITS ARE READ AS STRINGS; PRINT THEIR PRODUCT, OR AN ERROR
 * MESSAGE IF THE INPUT IS WRONG (A CHARACTER THAT IS NOT A DIGIT, OR MORE THAN 25 DIGITS)
 * THE STATEMENT ALLOWS THE KEYBOARD OR THE FILES INT.INP / IES.OUT: THE KEYBOARD IS USED
 * EXAMPLE: 13478654 54390123 -> 733105648934442
 * THE DIGITS ARE KEPT IN ARRAYS, THE LAST DIGIT FIRST: X[0] = UNITS, X[1] = TENS, ... */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXLEN 101 /* ROOM TO READ A WRONG, LONGER INPUT TOO */
#define DIGITS 25  /* A CORRECT NUMBER HAS AT MOST 25 DIGITS */

/* 1 IF S HAS FROM 1 TO 25 CHARACTERS, ALL OF THEM DIGITS; 0 OTHERWISE */
int is_correct(char s[])
{
	int len = strlen(s), i;

	if (len == 0 || len > DIGITS)
	{
		return 0;
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}

/* PUTS THE DIGITS OF S INTO X, THE LAST DIGIT FIRST; RETURNS HOW MANY DIGITS THERE ARE */
int to_digits(char s[], int x[])
{
	int len = strlen(s), i;

	for (i = 0; i < len; i++)
	{
		x[i] = s[len - 1 - i] - '0';
	}
	return len;
}

int main(void)
{
	char a[MAXLEN] = "", b[MAXLEN] = "";
	int x[DIGITS], y[DIGITS], r[2 * DIGITS];
	int la, lb, len, i, j;

	printf("First number: ");
	scanf("%100s", a);
	printf("Second number: ");
	scanf("%100s", b);

	if (is_correct(a) == 0 || is_correct(b) == 0)
	{
		printf("Wrong input data\n");
		return 0;
	}

	la = to_digits(a, x);
	lb = to_digits(b, y);
	len = la + lb; /* THE PRODUCT HAS AT MOST LA + LB DIGITS */
	for (i = 0; i < len; i++)
	{
		r[i] = 0;
	}
	/* AS ON PAPER: DIGIT I TIMES DIGIT J IS ADDED ON PLACE I + J */
	for (i = 0; i < la; i++)
	{
		for (j = 0; j < lb; j++)
		{
			r[i + j] = r[i + j] + x[i] * y[j];
		}
	}
	/* EVERY PLACE KEEPS ONE DIGIT AND CARRIES THE REST TO THE NEXT PLACE */
	for (i = 0; i < len - 1; i++)
	{
		r[i + 1] = r[i + 1] + r[i] / 10;
		r[i] = r[i] % 10;
	}
	while (len > 1 && r[len - 1] == 0)
	{
		len--; /* NO ZEROS IN FRONT OF THE PRODUCT */
	}

	printf("Product = ");
	for (i = len - 1; i >= 0; i--)
	{
		printf("%d", r[i]);
	}
	printf("\n");

	return 0;
}
