/* CULEGERE XIII.3.3 - WASPS ON THE ISLAND
 * ON DAY 1 THERE ARE P WASPS, ON DAY 2 Q WASPS, AND ON EVERY DAY K >= 3 THERE ARE 4 TIMES THE WASPS
 * OF DAY K-1 MINUS THE WASPS OF DAY K-2. VIESPI.IN HOLDS N, THEN P AND Q (ALL FROM 1 TO 100);
 * WRITE IN VIESPI.OUT THE NUMBER OF WASPS ON DAY N
 * THE NUMBERS GROW VERY FAST (UP TO 59 DIGITS ON DAY 100), SO THEY ARE KEPT DIGIT BY DIGIT
 * ASSUMPTION: SOME INPUTS MAKE THE FORMULA NEGATIVE (P = 100, Q = 1 GIVES -96 ON DAY 3); SUCH
 * VALUES ARE WRITTEN AS THE FORMULA GIVES THEM, WITH A MINUS SIGN
 * EXAMPLE: 4 / 2 3 -> 37 (DAY 3: 4 * 3 - 2 = 10, DAY 4: 4 * 10 - 3 = 37) */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF */

#define MAXD 100 /* DIGITS OF A BIG NUMBER */

/* A BIG NUMBER: DIGIT[0] IS THE UNITS DIGIT, LEN DIGITS ARE USED, SIGN IS 1 OR -1 */
typedef struct
{
	int digit[MAXD];
	int len;
	int sign;
} Big;

/* BIG NUMBER EQUAL TO A SMALL NATURAL VALUE (ALL UNUSED DIGITS ARE 0) */
Big make_big(int value)
{
	Big a;
	int i;

	for (i = 0; i < MAXD; i++)
	{
		a.digit[i] = 0;
	}
	a.len = 0;
	a.sign = 1;
	do
	{
		a.digit[a.len] = value % 10;
		a.len++;
		value = value / 10;
	} while (value > 0);
	return a;
}

/* COMPARES THE SIZES, WITHOUT THE SIGNS: 1 IF A IS LARGER, -1 IF B IS LARGER, 0 IF EQUAL */
int compare_size(Big a, Big b)
{
	int i;

	if (a.len != b.len)
	{
		if (a.len > b.len)
		{
			return 1;
		}
		return -1;
	}
	for (i = a.len - 1; i >= 0; i--)
	{
		if (a.digit[i] > b.digit[i])
		{
			return 1;
		}
		if (a.digit[i] < b.digit[i])
		{
			return -1;
		}
	}
	return 0;
}

/* SIZE OF A + SIZE OF B, DIGIT BY DIGIT WITH CARRY */
Big add_sizes(Big a, Big b)
{
	Big r = make_big(0);
	int i, sum, carry = 0;
	int len = a.len;

	if (b.len > len)
	{
		len = b.len;
	}
	for (i = 0; i < len; i++)
	{
		sum = a.digit[i] + b.digit[i] + carry;
		r.digit[i] = sum % 10;
		carry = sum / 10;
	}
	if (carry > 0)
	{
		r.digit[len] = carry;
		len++;
	}
	r.len = len;
	return r;
}

/* SIZE OF A - SIZE OF B, WHEN A IS NOT SMALLER, DIGIT BY DIGIT WITH BORROW */
Big subtract_sizes(Big a, Big b)
{
	Big r = make_big(0);
	int i, difference, borrow = 0;

	for (i = 0; i < a.len; i++)
	{
		difference = a.digit[i] - b.digit[i] - borrow;
		borrow = 0;
		if (difference < 0)
		{
			difference = difference + 10;
			borrow = 1;
		}
		r.digit[i] = difference;
	}
	r.len = a.len;
	while (r.len > 1 && r.digit[r.len - 1] == 0)
	{
		r.len--; /* DROP THE ZEROS IN FRONT */
	}
	return r;
}

/* A * M, FOR A SMALL NATURAL NUMBER M */
Big multiply_small(Big a, int m)
{
	int i, product, carry = 0;

	for (i = 0; i < a.len; i++)
	{
		product = a.digit[i] * m + carry;
		a.digit[i] = product % 10;
		carry = product / 10;
	}
	while (carry > 0)
	{
		a.digit[a.len] = carry % 10;
		a.len++;
		carry = carry / 10;
	}
	return a;
}

/* A - B FOR BIG NUMBERS WITH SIGNS */
Big subtract(Big a, Big b)
{
	Big r;

	if (a.sign != b.sign)
	{
		/* (+A) - (-B) = +(A + B) AND (-A) - (+B) = -(A + B) */
		r = add_sizes(a, b);
		r.sign = a.sign;
	}
	else if (compare_size(a, b) >= 0)
	{
		/* SAME SIGNS: THE LARGER SIZE MINUS THE SMALLER ONE KEEPS THE SIGN OF A */
		r = subtract_sizes(a, b);
		r.sign = a.sign;
	}
	else
	{
		r = subtract_sizes(b, a);
		r.sign = -a.sign;
	}
	if (r.len == 1 && r.digit[0] == 0)
	{
		r.sign = 1; /* ZERO IS WRITTEN WITHOUT A MINUS */
	}
	return r;
}

/* WRITES A BIG NUMBER, FROM ITS FIRST DIGIT DOWN TO THE UNITS */
void write_big(FILE *out, Big a)
{
	int i;

	if (a.sign < 0)
	{
		fprintf(out, "-");
	}
	for (i = a.len - 1; i >= 0; i--)
	{
		fprintf(out, "%d", a.digit[i]);
	}
	fprintf(out, "\n");
}

int main(void)
{
	FILE *in = fopen("VIESPI.IN", "r");
	FILE *out;
	int n = 0, p = 0, q = 0, k;
	Big before, last, today;

	if (in == NULL)
	{
		printf("Cannot open VIESPI.IN\n");
		return 1;
	}
	fscanf(in, "%d %d %d", &n, &p, &q);
	fclose(in);

	before = make_big(p); /* THE WASPS OF DAY K-2 */
	last = make_big(q);   /* THE WASPS OF DAY K-1 */
	if (n == 1)
	{
		last = before;
	}
	for (k = 3; k <= n; k++)
	{
		today = subtract(multiply_small(last, 4), before);
		before = last;
		last = today;
	}

	out = fopen("VIESPI.OUT", "w");
	write_big(out, last);
	fclose(out);

	return 0;
}
