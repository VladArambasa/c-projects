/* CULEGERE XIII.3.5 - WORD DICTIONARY CIPHER
 * COD.IN HAS ONE LINE: THE LETTER C (ENCRYPT) AND, RIGHT AFTER IT, A MESSAGE OF LOWERCASE WORDS
 * (AT MOST 10 LETTERS EACH) SEPARATED BY SINGLE SPACES. THE DICTIONARY HOLDS EVERY DIFFERENT WORD
 * OF THE MESSAGE AND THE SPACE (AT MOST 15 ENTRIES), SORTED ALPHABETICALLY; K IS THE SMALLEST
 * NUMBER WITH (NUMBER OF ENTRIES) < 2 TO THE POWER K. EVERY WORD AND EVERY SPACE OF THE MESSAGE IS
 * REPLACED BY ITS POSITION IN THE DICTIONARY (FROM 1) WRITTEN IN BASE 2 ON K BITS; THE BITS ARE
 * CUT INTO GROUPS OF 8 (THE LAST GROUP IS COMPLETED WITH 0) AND EACH GROUP IS THE CODE OF ONE
 * CHARACTER. COD.OUT GETS THESE CHARACTERS AND, RIGHT AFTER THEM, THE DICTIONARY ENTRIES SEPARATED
 * BY SPACES
 * EXAMPLE: MAMA ARE MERE -> DICTIONARY " " ARE MAMA MERE, K = 3, BITS 011 001 010 001 100 AND A 0,
 * CHARACTER CODES 101 AND 24, THEN "  ARE MAMA MERE" (THE SPACE ENTRY AND A SEPARATOR) */
#include <stdio.h>  /* PRINTF, FOPEN, FGETS, FPUTC, FPRINTF */
#include <string.h> /* STRCMP, STRCPY */

#define MAXLINE 1003   /* THE LINE OF COD.IN */
#define MAXTOKENS 1000 /* WORDS AND SPACES OF THE MESSAGE */
#define MAXWORD 11     /* 10 LETTERS AND THE END OF THE STRING */
#define MAXDICT 16

char token[MAXTOKENS][MAXWORD]; /* THE MESSAGE: ITS WORDS AND SPACES, IN ORDER */
char dict[MAXDICT][MAXWORD];    /* THE DICTIONARY */
int bit[4 * MAXTOKENS + 8];     /* THE BITS OF THE CODED MESSAGE */

/* 1 FOR A CHARACTER THAT ENDS THE LINE */
int end_of_line(char ch)
{
	return ch == '\0' || ch == '\n' || ch == '\r';
}

/* SPLITS THE MESSAGE (THE LINE WITHOUT ITS FIRST CHARACTER) INTO WORDS AND SPACES;
 * RETURNS HOW MANY PIECES THERE ARE */
int split_message(char line[])
{
	int i = 1, count = 0, len;

	while (end_of_line(line[i]) == 0)
	{
		if (line[i] == ' ')
		{
			strcpy(token[count], " ");
			i++;
		}
		else
		{
			len = 0;
			while (line[i] != ' ' && end_of_line(line[i]) == 0)
			{
				token[count][len] = line[i];
				len++;
				i++;
			}
			token[count][len] = '\0';
		}
		count++;
	}
	return count;
}

/* POSITION OF A WORD IN THE DICTIONARY OF SIZE ENTRIES (FROM 0), OR -1 IF IT IS NOT THERE */
int find_word(char word[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (strcmp(dict[i], word) == 0)
		{
			return i;
		}
	}
	return -1;
}

/* SORTS THE DICTIONARY ALPHABETICALLY (THE SPACE HAS THE SMALLEST CODE, SO IT COMES FIRST) */
void sort_dictionary(int size)
{
	int i, j;
	char temp[MAXWORD];

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(dict[i], dict[j]) > 0)
			{
				strcpy(temp, dict[i]);
				strcpy(dict[i], dict[j]);
				strcpy(dict[j], temp);
			}
		}
	}
}

int main(void)
{
	FILE *in = fopen("COD.IN", "r");
	FILE *out;
	char line[MAXLINE] = "";
	int tokens, size, i, j, k, power, position, bits, value;

	if (in == NULL)
	{
		printf("Cannot open COD.IN\n");
		return 1;
	}
	fgets(line, MAXLINE, in);
	fclose(in);
	tokens = split_message(line);

	/* 1. THE DICTIONARY: EVERY DIFFERENT WORD (OR SPACE) ONCE, THEN SORTED */
	size = 0;
	for (i = 0; i < tokens; i++)
	{
		if (find_word(token[i], size) == -1)
		{
			strcpy(dict[size], token[i]);
			size++;
		}
	}
	sort_dictionary(size);

	/* 2. K: THE SMALLEST NUMBER WITH SIZE < 2 TO THE POWER K */
	k = 1;
	power = 2;
	while (size >= power)
	{
		k++;
		power = power * 2;
	}

	/* 3. EVERY PIECE OF THE MESSAGE BECOMES ITS POSITION (FROM 1) IN BASE 2, ON K BITS */
	bits = 0;
	for (i = 0; i < tokens; i++)
	{
		position = find_word(token[i], size) + 1;
		for (j = k - 1; j >= 0; j--)
		{
			bit[bits + j] = position % 2; /* THE LAST BIT IS FOUND FIRST */
			position = position / 2;
		}
		bits = bits + k;
	}

	/* 4. THE LAST GROUP OF 8 BITS IS COMPLETED WITH 0 */
	while (bits % 8 != 0)
	{
		bit[bits] = 0;
		bits++;
	}

	/* 5. EVERY GROUP OF 8 BITS IS THE CODE OF ONE CHARACTER; THEN COMES THE DICTIONARY.
	 * THE FILE IS BINARY ("WB") BECAUSE A CODE CAN BE ANY VALUE FROM 0 TO 255 */
	out = fopen("COD.OUT", "wb");
	for (i = 0; i < bits; i = i + 8)
	{
		value = 0;
		for (j = i; j < i + 8; j++)
		{
			value = value * 2 + bit[j];
		}
		fputc(value, out);
	}
	for (i = 0; i < size; i++)
	{
		if (i > 0)
		{
			fputc(' ', out);
		}
		fprintf(out, "%s", dict[i]);
	}
	fprintf(out, "\n");
	fclose(out);

	return 0;
}
