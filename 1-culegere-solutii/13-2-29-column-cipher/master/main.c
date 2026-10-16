/* CULEGERE XIII.2.29 - COLUMN CIPHER
 * THE FIRST CHARACTER OF THE MESSAGE IS C (CODE) OR D (DECODE), CAPITAL OR SMALL, GLUED TO THE
 * TEXT. CODING: WRITE THE TEXT IN ROWS OF 5 CHARACTERS (AS MANY ROWS AS NEEDED), THEN READ IT BY
 * COLUMNS, FROM TOP TO BOTTOM AND FROM LEFT TO RIGHT, WITH A DOT FOR EVERY SPACE AND FOR EVERY
 * EMPTY PLACE LEFT AT THE END OF THE TABLE. DECODING DOES THE SAME STEPS BACKWARDS
 * EXAMPLES (SHOWN IN CAPITALS; THE CASE OF EVERY LETTER IS KEPT): CAM UN MAR -> A.MM.AURN.
 *          DTAGIA.AUBLLCAAA.R.C. -> TABARA LA GALACIUC
 * ASSUMPTION: A MESSAGE TO DECODE HAS A MULTIPLE OF 5 CHARACTERS; THE DOTS AT ITS END ARE
 * DROPPED (THEY ONLY FILLED THE TABLE) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXLEN 260 /* THE COMMAND LETTER, THE TEXT, THE NEW LINE MARK AND THE END MARK */
#define COLS 5
#define MAXROWS 52 /* ENOUGH ROWS OF 5 FOR THE LONGEST TEXT */

char grid[MAXROWS][COLS]; /* THE TABLE WITH 5 CHARACTERS ON EVERY ROW */

/* READS A LINE FROM THE KEYBOARD AND REMOVES THE NEW LINE MARK AT ITS END */
void read_line(char s[], int size)
{
	int len;

	if (fgets(s, size, stdin) == NULL)
	{
		s[0] = '\0';
	}
	len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
	}
}

/* CODES THE TEXT AND PRINTS THE RESULT */
void encode(char text[])
{
	int len = strlen(text);
	int rows = (len + COLS - 1) / COLS; /* ENOUGH ROWS FOR ALL THE CHARACTERS */
	int r, c, k = 0;

	/* WRITE THE TEXT ROW BY ROW; SPACES AND THE EMPTY PLACES AT THE END BECOME DOTS */
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < COLS; c++)
		{
			if (k < len && text[k] != ' ')
			{
				grid[r][c] = text[k];
			}
			else
			{
				grid[r][c] = '.';
			}
			k++;
		}
	}
	/* READ THE TABLE COLUMN BY COLUMN */
	for (c = 0; c < COLS; c++)
	{
		for (r = 0; r < rows; r++)
		{
			printf("%c", grid[r][c]);
		}
	}
	printf("\n");
}

/* DECODES THE TEXT AND PRINTS THE RESULT */
void decode(char text[])
{
	char result[MAXLEN];
	int len = strlen(text);
	int rows = len / COLS;
	int r, c, k = 0;

	/* THE CODE WAS READ COLUMN BY COLUMN, SO IT GOES BACK INTO THE TABLE THE SAME WAY */
	for (c = 0; c < COLS; c++)
	{
		for (r = 0; r < rows; r++)
		{
			grid[r][c] = text[k];
			k++;
		}
	}
	/* READ THE TABLE ROW BY ROW; THE DOTS BECOME SPACES AGAIN */
	k = 0;
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < COLS; c++)
		{
			if (grid[r][c] == '.')
			{
				result[k] = ' ';
			}
			else
			{
				result[k] = grid[r][c];
			}
			k++;
		}
	}
	/* THE SPACES AT THE END ONLY FILLED THE LAST ROW OF THE TABLE */
	while (k > 0 && result[k - 1] == ' ')
	{
		k--;
	}
	result[k] = '\0';
	printf("%s\n", result);
}

int main(void)
{
	char line[MAXLEN] = "", text[MAXLEN] = "";
	int i, len;

	printf("Message (C to code or D to decode, then the text): ");
	read_line(line, MAXLEN);
	len = strlen(line);
	/* THE TEXT IS EVERYTHING AFTER THE COMMAND LETTER */
	for (i = 1; i <= len; i++)
	{
		text[i - 1] = line[i];
	}

	if (line[0] == 'C' || line[0] == 'c')
	{
		encode(text);
	}
	else if (line[0] == 'D' || line[0] == 'd')
	{
		decode(text);
	}
	return 0;
}
