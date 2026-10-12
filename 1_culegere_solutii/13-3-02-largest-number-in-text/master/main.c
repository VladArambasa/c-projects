/* CULEGERE XIII.3.2 - LARGEST NUMBER IN A TEXT
 * NRMAX.IN HOLDS ONE LINE OF 1 TO 1000 CHARACTERS (ENGLISH LETTERS AND DIGITS); THE NUMBERS OF THE
 * LINE ARE ITS GROUPS OF CONSECUTIVE DIGITS. WRITE THE LARGEST OF THEM IN NRMAX.OUT, OR -1 IF THE
 * LINE HAS NO DIGIT. A NUMBER CAN HAVE UP TO 1000 DIGITS, SO NUMBERS ARE COMPARED AS STRINGS
 * ASSUMPTION: LEADING ZEROS DO NOT CHANGE A NUMBER (007 IS 7), SO THEY ARE NOT WRITTEN
 * EXAMPLE: A78BX899F7G9 -> 899 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 1003 /* 1000 CHARACTERS, THE END OF LINE AND THE END OF THE STRING */

/* 1 FOR A DIGIT CHARACTER */
int is_digit(char ch)
{
	return ch >= '0' && ch <= '9';
}

/* 1 IF NUMBER A IS GREATER THAN NUMBER B (BOTH WITHOUT LEADING ZEROS): MORE DIGITS MEANS
 * GREATER, NUMBERS WITH AS MANY DIGITS ARE COMPARED DIGIT BY DIGIT, LIKE WORDS */
int is_greater(char a[], char b[])
{
	int len_a = strlen(a);
	int len_b = strlen(b);

	if (len_a != len_b)
	{
		return len_a > len_b;
	}
	return strcmp(a, b) > 0;
}

int main(void)
{
	FILE *in = fopen("nrmax.in", "r");
	FILE *out;
	char line[MAX] = "";
	char number[MAX];
	char best[MAX] = "";
	int i, len, found;

	if (in == NULL)
	{
		printf("Cannot open nrmax.in\n");
		return 1;
	}
	fgets(line, MAX, in);
	fclose(in);

	found = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (is_digit(line[i]))
		{
			/* SKIP THE ZEROS IN FRONT OF THE GROUP, BUT KEEP ITS LAST DIGIT */
			while (line[i] == '0' && is_digit(line[i + 1]))
			{
				i++;
			}
			/* COPY THE REST OF THE GROUP OF DIGITS */
			len = 0;
			while (is_digit(line[i]))
			{
				number[len] = line[i];
				len++;
				i++;
			}
			number[len] = '\0';
			if (found == 0 || is_greater(number, best))
			{
				strcpy(best, number);
				found = 1;
			}
		}
		else
		{
			i++;
		}
	}

	out = fopen("nrmax.out", "w");
	if (found == 1)
	{
		fprintf(out, "%s\n", best);
	}
	else
	{
		fprintf(out, "-1\n");
	}
	fclose(out);

	return 0;
}
