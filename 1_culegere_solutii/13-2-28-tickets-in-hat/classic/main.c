/* CULEGERE XIII.2.28 - TICKETS IN THE HAT
 * N HAS AT MOST 9 DIGITS, ALL DIFFERENT AND NOT 0; EVERY DIGIT HAS A TICKET. START ON THE LAST
 * DIGIT AND PUT ITS TICKET IN THE HAT. FROM AN EVEN DIGIT WALK TO THE RIGHT, FROM AN ODD ONE TO
 * THE LEFT, AS MANY STEPS AS THE DIGIT (AFTER THE LAST DIGIT COMES THE FIRST, BEFORE THE FIRST
 * COMES THE LAST) AND PUT THE TICKET OF THE DIGIT REACHED, AND SO ON. STOP WHEN ALL THE TICKETS
 * ARE IN THE HAT (PRINT THE LAST ONE PUT) OR WHEN THE TICKET OF THE DIGIT REACHED IS ALREADY
 * THERE (PRINT THAT DIGIT)
 * EXAMPLES: 412 -> 4, 1243 -> 3 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAXD 9

/* PUTS THE DIGITS OF N IN D, THE FIRST DIGIT IN D[0]; RETURNS HOW MANY DIGITS N HAS */
int get_digits(int n, int d[])
{
	int reversed[MAXD];
	int count = 0, i;

	do
	{
		reversed[count] = n % 10; /* THE DIGITS COME OUT FROM THE LAST ONE */
		n = n / 10;
		count++;
	} while (n > 0);
	for (i = 0; i < count; i++)
	{
		d[i] = reversed[count - 1 - i]; /* TURN THEM AROUND */
	}
	return count;
}

/* WALKS STEPS PLACES FROM POSITION POS: TO THE RIGHT IF STEPS IS EVEN, TO THE LEFT IF IT IS ODD;
 * RETURNS THE POSITION REACHED */
int walk(int pos, int steps, int len)
{
	int s;

	for (s = 1; s <= steps; s++)
	{
		if (steps % 2 == 0)
		{
			pos++;
			if (pos == len)
			{
				pos = 0; /* AFTER THE LAST DIGIT COMES THE FIRST ONE */
			}
		}
		else
		{
			pos--;
			if (pos < 0)
			{
				pos = len - 1; /* BEFORE THE FIRST DIGIT COMES THE LAST ONE */
			}
		}
	}
	return pos;
}

int main(void)
{
	int digit[MAXD], in_hat[MAXD];
	int n = 0, len, pos, i, placed, stop = 0;

	printf("N = ");
	scanf("%d", &n);
	len = get_digits(n, digit);
	for (i = 0; i < len; i++)
	{
		in_hat[i] = 0;
	}

	pos = len - 1; /* START WITH THE LAST DIGIT */
	in_hat[pos] = 1;
	placed = 1;
	while (placed < len && stop == 0)
	{
		pos = walk(pos, digit[pos], len);
		if (in_hat[pos] == 1)
		{
			stop = 1; /* THIS TICKET IS ALREADY IN THE HAT */
		}
		else
		{
			in_hat[pos] = 1;
			placed++;
		}
	}
	/* IN BOTH CASES THE ANSWER IS THE DIGIT WHERE GIGEL STOPPED */
	printf("%d\n", digit[pos]);
	return 0;
}
