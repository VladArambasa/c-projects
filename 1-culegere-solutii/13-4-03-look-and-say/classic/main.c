/* CULEGERE XIII.4.3 - LOOK AND SAY SEQUENCE
 * THE SEQUENCE 1, 11, 21, 1211, 111221, ... STARTS WITH 1 AND EVERY NEXT TERM DESCRIBES THE ONE
 * BEFORE IT (1211 IS "ONE 1, ONE 2, TWO 1", SO THE NEXT TERM IS 111221). SIR.IN HOLDS N
 * (4 <= N <= 35); WRITE THE N-TH TERM IN SIR.OUT. A TERM HAS UP TO 17000 DIGITS (16774 FOR N = 35),
 * SO IT IS KEPT AS A STRING OF DIGITS
 * EXAMPLE: 4 -> 1211; 5 -> 111221 */
#include <stdio.h>  /* PRINTF, FOPEN, FSCANF, FPRINTF */
#include <string.h> /* STRCPY */

#define MAXD 17001

char term[MAXD]; /* THE CURRENT TERM */
char next[MAXD]; /* THE TERM AFTER IT */

/* WRITES IN NEXT THE DESCRIPTION OF TERM: FOR EVERY GROUP OF EQUAL DIGITS, HOW MANY AND WHICH */
void describe(void)
{
	int i = 0, len = 0, count;
	char digit;

	while (term[i] != '\0')
	{
		digit = term[i];
		count = 0;
		while (term[i] == digit)
		{
			count++;
			i++;
		}
		next[len] = '0' + count; /* A GROUP NEVER HAS MORE THAN 3 EQUAL DIGITS */
		next[len + 1] = digit;
		len = len + 2;
	}
	next[len] = '\0';
}

int main(void)
{
	FILE *in = fopen("SIR.IN", "r");
	FILE *out;
	int n = 0, k;

	if (in == NULL)
	{
		printf("Cannot open SIR.IN\n");
		return 1;
	}
	fscanf(in, "%d", &n);
	fclose(in);

	strcpy(term, "1");
	for (k = 2; k <= n; k++)
	{
		describe();
		strcpy(term, next);
	}

	out = fopen("SIR.OUT", "w");
	fprintf(out, "%s\n", term);
	fclose(out);

	return 0;
}
