/* CULEGERE IX.1.5 - COMMON HEXADECIMAL DIGITS
 * TWO NUMBERS IN BASE 16 WITH AT MOST 255 DIGITS ARE READ; PRINT THE DIGITS THEY HAVE IN COMMON
 * (A DIGIT FROM A TO F MAY BE WRITTEN AS A SMALL OR AS A CAPITAL LETTER)
 * EXAMPLE: 1A67FB 56DB345AA -> 6 A B
 * A SET OF DIGITS IS AN ARRAY OF 16 FLAGS, ONE FOR EACH DIGIT FROM 0 TO F */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXLEN 256 /* AT MOST 255 DIGITS */

/* THE VALUE OF A HEXADECIMAL DIGIT: 0..9, THEN A..F MEAN 10..15 */
int digit_value(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	return toupper(c) - 'A' + 10; /* A SMALL LETTER IS FIRST TURNED INTO A CAPITAL */
}

/* MARKS IN SET THE DIGITS USED BY THE NUMBER S */
void digit_set(char s[], int set[])
{
	int i, len = strlen(s);

	for (i = 0; i < 16; i++)
	{
		set[i] = 0;
	}
	for (i = 0; i < len; i++)
	{
		set[digit_value(s[i])] = 1;
	}
}

int main(void)
{
	char a[MAXLEN] = "", b[MAXLEN] = "";
	char symbol[] = "0123456789ABCDEF"; /* SYMBOL[D] IS HOW DIGIT D IS WRITTEN */
	int in_a[16], in_b[16];
	int d, found = 0;

	printf("First number: ");
	scanf("%255s", a);
	printf("Second number: ");
	scanf("%255s", b);

	digit_set(a, in_a);
	digit_set(b, in_b);

	printf("Common digits:");
	for (d = 0; d < 16; d++)
	{
		if (in_a[d] == 1 && in_b[d] == 1) /* THE INTERSECTION OF THE TWO SETS */
		{
			printf(" %c", symbol[d]);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf(" none");
	}
	printf("\n");

	return 0;
}
