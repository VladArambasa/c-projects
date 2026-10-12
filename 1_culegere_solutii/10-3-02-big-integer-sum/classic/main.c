/* CULEGERE X.3.2 - SUM OF TWO BIG INTEGERS
 * THE FILE TERMENI.INT HOLDS TWO INTEGERS OF AT MOST 100 DIGITS EACH; PRINT THEIR SUM ON THE SCREEN
 * ASSUMPTION: AN INTEGER MAY START WITH A MINUS SIGN (OR A PLUS SIGN); THE TWO NUMBERS ARE
 * SEPARATED BY SPACES OR NEW LINES
 * EXAMPLE: 123456789012345678901234567890 987654321098765432109876543210
 *          -> 1111111110111111111011111111100; -1000 1 -> -999
 * THE DIGITS ARE KEPT IN ARRAYS, THE LAST DIGIT FIRST: X[0] = UNITS, X[1] = TENS, ... */
#include <stdio.h>  /* PRINTF, FOPEN, FSCANF, FCLOSE */
#include <string.h> /* STRLEN */

#define MAXLEN 102 /* A SIGN, 100 DIGITS AND THE END OF THE STRING */
#define MAXD 101   /* 100 DIGITS AND ONE MORE FOR THE LAST CARRY */

/* PUTS THE DIGITS OF S INTO X, THE LAST DIGIT FIRST, AND ZEROS IN THE REST OF X;
 * RETURNS HOW MANY DIGITS THE NUMBER HAS (WITHOUT ZEROS IN FRONT) */
int to_digits(char s[], int x[])
{
	int len = strlen(s), start = 0, i, count = 0;

	for (i = 0; i < MAXD; i++)
	{
		x[i] = 0;
	}
	if (s[0] == '-' || s[0] == '+')
	{
		start = 1; /* THE SIGN IS NOT A DIGIT */
	}
	for (i = len - 1; i >= start; i--)
	{
		x[count] = s[i] - '0';
		count++;
	}
	while (count > 1 && x[count - 1] == 0)
	{
		count--; /* 007 IS 7 */
	}
	return count;
}

/* COMPARES THE NUMBERS WITHOUT THEIR SIGNS: 1 IF X IS BIGGER, -1 IF Y IS BIGGER, 0 IF EQUAL */
int compare(int x[], int lx, int y[], int ly)
{
	int i;

	if (lx != ly)
	{
		if (lx > ly)
		{
			return 1;
		}
		return -1; /* MORE DIGITS MEANS A BIGGER NUMBER */
	}
	for (i = lx - 1; i >= 0; i--)
	{
		if (x[i] != y[i]) /* THE FIRST DIFFERENT DIGIT FROM THE LEFT DECIDES */
		{
			if (x[i] > y[i])
			{
				return 1;
			}
			return -1;
		}
	}
	return 0;
}

/* R = X + Y, DIGIT BY DIGIT WITH THE CARRY; LEN IS THE LENGTH OF THE LONGER NUMBER;
 * RETURNS THE LENGTH OF R */
int add(int x[], int y[], int len, int r[])
{
	int i, carry = 0, s;

	for (i = 0; i < len; i++)
	{
		s = x[i] + y[i] + carry;
		r[i] = s % 10;
		carry = s / 10;
	}
	if (carry > 0)
	{
		r[len] = carry; /* ONE MORE DIGIT IN FRONT */
		len++;
	}
	return len;
}

/* R = X - Y, WHERE X IS NOT SMALLER THAN Y AND HAS LEN DIGITS; RETURNS THE LENGTH OF R */
int subtract(int x[], int y[], int len, int r[])
{
	int i, borrow = 0, d;

	for (i = 0; i < len; i++)
	{
		d = x[i] - y[i] - borrow;
		borrow = 0;
		if (d < 0)
		{
			d = d + 10; /* BORROW 1 FROM THE NEXT DIGIT */
			borrow = 1;
		}
		r[i] = d;
	}
	while (len > 1 && r[len - 1] == 0)
	{
		len--; /* 1000 - 999 = 0001, WHICH IS 1 */
	}
	return len;
}

int main(void)
{
	FILE *f = fopen("termeni.int", "r");
	char a[MAXLEN] = "", b[MAXLEN] = "";
	int x[MAXD], y[MAXD], r[MAXD];
	int lx, ly, lr, sign_x, sign_y, sign, i;

	if (f == NULL)
	{
		printf("Cannot open termeni.int\n");
		return 1;
	}
	fscanf(f, "%101s %101s", a, b);
	fclose(f);

	sign_x = 1;
	if (a[0] == '-')
	{
		sign_x = -1;
	}
	sign_y = 1;
	if (b[0] == '-')
	{
		sign_y = -1;
	}
	lx = to_digits(a, x);
	ly = to_digits(b, y);

	if (sign_x == sign_y) /* THE SAME SIGN: ADD THE DIGITS AND KEEP THE SIGN */
	{
		if (lx > ly)
		{
			lr = add(x, y, lx, r);
		}
		else
		{
			lr = add(x, y, ly, r);
		}
		sign = sign_x;
	}
	else if (compare(x, lx, y, ly) >= 0) /* DIFFERENT SIGNS: |X| - |Y|, WITH THE SIGN OF X */
	{
		lr = subtract(x, y, lx, r);
		sign = sign_x;
	}
	else /* |Y| IS BIGGER: |Y| - |X|, WITH THE SIGN OF Y */
	{
		lr = subtract(y, x, ly, r);
		sign = sign_y;
	}
	if (lr == 1 && r[0] == 0)
	{
		sign = 1; /* 0 HAS NO SIGN */
	}

	printf("Sum = ");
	if (sign == -1)
	{
		printf("-");
	}
	for (i = lr - 1; i >= 0; i--)
	{
		printf("%d", r[i]);
	}
	printf("\n");

	return 0;
}
