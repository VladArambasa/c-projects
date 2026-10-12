/* CULEGERE XIII.3.7 - EXPRESSION WITH PLUS AND MINUS (THE SAME PROBLEM AS XIII.3.1)
 * EXPRESIE.IN HOLDS THE VALUES OF THE OPERANDS A, B, C (NATURAL, NOT ZERO, BELOW 32000) ON THE
 * FIRST LINE AND, ON THE SECOND LINE, AN EXPRESSION OF AT MOST 1000 CHARACTERS MADE OF THE SMALL
 * LETTERS A, B, C AND THE OPERATORS + AND -; WRITE THE VALUE OF THE EXPRESSION IN EXPRESIE.OUT
 * EXAMPLE: 7 8 3 / A+C-B+C -> 5 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

/* VALUE OF THE OPERAND WITH THE GIVEN NAME */
int operand_value(int name, int a, int b, int c)
{
	if (name == 'a')
	{
		return a;
	}
	if (name == 'b')
	{
		return b;
	}
	return c;
}

int main(void)
{
	FILE *in = fopen("expresie.in", "r");
	FILE *out;
	int a = 0, b = 0, c = 0;
	int ch, sign, value;

	if (in == NULL)
	{
		printf("Cannot open expresie.in\n");
		return 1;
	}
	fscanf(in, "%d %d %d", &a, &b, &c);

	/* THE EXPRESSION IS READ CHARACTER BY CHARACTER: AN OPERATOR GIVES THE SIGN
	 * OF THE NEXT OPERAND, AN OPERAND IS ADDED TO THE VALUE WITH THAT SIGN */
	value = 0;
	sign = 1;
	ch = fgetc(in);
	while (ch != EOF)
	{
		if (ch == '+')
		{
			sign = 1;
		}
		else if (ch == '-')
		{
			sign = -1;
		}
		else if (ch == 'a' || ch == 'b' || ch == 'c')
		{
			value = value + sign * operand_value(ch, a, b, c);
		}
		ch = fgetc(in);
	}
	fclose(in);

	out = fopen("expresie.out", "w");
	fprintf(out, "%d\n", value);
	fclose(out);

	return 0;
}
