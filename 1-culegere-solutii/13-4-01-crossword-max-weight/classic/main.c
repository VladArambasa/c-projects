/* CULEGERE XIII.4.1 - CROSSWORD WITH MAXIMUM WEIGHT
 * A SQUARE GRID OF N X N CELLS, SOME OF THEM BLACK, IS FILLED WITH SMALL LETTERS FROM A LIST WHERE
 * EVERY LETTER HAS A WEIGHT. A WORD IS A RUN OF AT LEAST 2 LETTERS OF A ROW OR OF A COLUMN (BETWEEN
 * BLACK CELLS OR BORDERS); A WORD MAY NOT HAVE X CONSECUTIVE CONSONANTS, Y CONSECUTIVE VOWELS (THE
 * VOWELS ARE A, E, I, O, U) OR TWO EQUAL LETTERS SIDE BY SIDE. A WORD IS MASCULINE IF IT STARTS AND
 * ENDS WITH A CONSONANT, FEMININE IF IT STARTS AND ENDS WITH A VOWEL, AND NEUTER OTHERWISE.
 * FILL THE GRID WITH EXACTLY THE GIVEN NUMBERS OF MASCULINE, FEMININE AND NEUTER WORDS, SO THAT
 * THE WEIGHT OF THE COLUMNS IS THE LARGEST. THE INPUT FILE (ITS NAME IS TYPED AT THE KEYBOARD)
 * HOLDS N, X, Y; THE ROW AND THE COLUMN OF EVERY BLACK CELL; THE NUMBERS OF MASCULINE, FEMININE
 * AND NEUTER WORDS; THEN THE PAIRS WEIGHT LETTER. CNI.OUT GETS THE GRID (BLACK CELLS AS *) AND THE
 * LARGEST WEIGHT
 * IDEA: BACKTRACKING CELL BY CELL, ROW BY ROW: A LETTER IS KEPT ONLY IF ITS WORDS STILL RESPECT
 * THE RULES, AND A BRANCH IS DROPPED WHEN EVEN THE HEAVIEST LETTER IN EVERY COLUMN WORD CELL LEFT
 * COULD NOT BEAT THE BEST GRID FOUND SO FAR
 * ASSUMPTION: THE WEIGHT OF THE COLUMNS IS THE SUM OF THE WEIGHTS OF THE LETTERS OF THE COLUMN
 * WORDS (THIS GIVES 1160 FOR THE BOOK'S GRID); A LETTER ALONE BETWEEN BLACK CELLS IS NOT A WORD
 * ASSUMPTION: THE GRID IS SMALL (N <= 10); THE SEARCH TRIES VERY MANY FILLINGS, SO IT IS QUICK UP
 * TO N = 6 BUT MAY TAKE SECONDS OR MORE FROM N = 7 ON
 * NOTE: THE BOOK'S EXAMPLE SAYS 1160 (GRID CADC AB*A CDAB *ABC); THE CORRECT RESULT IS 1210, FOR
 * EXAMPLE WITH THE GRID CABC AC*A CBAC *ACB, WHICH RESPECTS EVERY RULE
 * EXAMPLE: 4 3 3 / 2 3 4 1 / 4 1 3 / 100 C / 80 B / 90 A / 70 D -> 1210 */
#include <stdio.h> /* PRINTF, SCANF, FOPEN, FGETS, SSCANF, FSCANF, FPRINTF */

#define MAXN 10       /* LARGEST GRID SIDE */
#define MAXLETTERS 26
#define MAXLINE 1000

int n, x, y;                    /* GRID SIDE, FORBIDDEN CONSONANT RUN, FORBIDDEN VOWEL RUN */
int black[MAXN][MAXN];          /* 1 FOR A BLACK CELL */
char grid[MAXN][MAXN];          /* THE GRID BEING FILLED */
char best_grid[MAXN][MAXN];     /* THE BEST GRID FOUND SO FAR */
int best_weight = -1;           /* ITS WEIGHT, -1 WHILE NO GRID WAS FOUND */
int need[3];                    /* WORDS WANTED: 0 MASCULINE, 1 FEMININE, 2 NEUTER */
int have[3];                    /* FINISHED WORDS OF EACH GENDER IN THE GRID BEING FILLED */
char letter[MAXLETTERS];        /* THE LETTERS, THE HEAVIEST FIRST */
int weight[MAXLETTERS];
int letters;
int in_row_word[MAXN][MAXN];    /* 1 IF THE CELL BELONGS TO A ROW WORD */
int in_col_word[MAXN][MAXN];    /* 1 IF THE CELL BELONGS TO A COLUMN WORD */
int row_start[MAXN][MAXN];      /* THE COLUMN WHERE THE ROW RUN OF THE CELL STARTS */
int col_start[MAXN][MAXN];      /* THE ROW WHERE THE COLUMN RUN OF THE CELL STARTS */
int col_cells_left[MAXN * MAXN + 1]; /* COLUMN WORD CELLS FROM A POSITION TO THE END */

/* 1 FOR A VOWEL */
int is_vowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

/* GENDER OF A WORD FROM ITS FIRST AND LAST LETTERS: 0 MASCULINE, 1 FEMININE, 2 NEUTER */
int gender(char first, char last)
{
	if (is_vowel(first) == 0 && is_vowel(last) == 0)
	{
		return 0;
	}
	if (is_vowel(first) == 1 && is_vowel(last) == 1)
	{
		return 1;
	}
	return 2;
}

/* 1 IF RUN CONSECUTIVE LETTERS OF THE KIND OF CH (VOWELS OR CONSONANTS) ARE TOO MANY */
int run_too_long(char ch, int run)
{
	if (is_vowel(ch) == 1)
	{
		return run >= y;
	}
	return run >= x;
}

/* FINDS THE RUNS OF WHITE CELLS OF EVERY ROW (A RUN OF AT LEAST 2 CELLS IS A WORD);
 * RETURNS THE NUMBER OF ROW WORDS */
int find_row_words(void)
{
	int i, j, k, start, words = 0;

	for (i = 0; i < n; i++)
	{
		j = 0;
		while (j < n)
		{
			if (black[i][j] == 1)
			{
				j++;
			}
			else
			{
				start = j;
				while (j < n && black[i][j] == 0)
				{
					j++;
				}
				/* THE CELLS START .. J - 1 FORM ONE RUN */
				for (k = start; k < j; k++)
				{
					row_start[i][k] = start;
					if (j - start >= 2)
					{
						in_row_word[i][k] = 1;
					}
				}
				if (j - start >= 2)
				{
					words++;
				}
			}
		}
	}
	return words;
}

/* THE SAME FOR THE COLUMNS; RETURNS THE NUMBER OF COLUMN WORDS */
int find_col_words(void)
{
	int i, j, k, start, words = 0;

	for (j = 0; j < n; j++)
	{
		i = 0;
		while (i < n)
		{
			if (black[i][j] == 1)
			{
				i++;
			}
			else
			{
				start = i;
				while (i < n && black[i][j] == 0)
				{
					i++;
				}
				for (k = start; k < i; k++)
				{
					col_start[k][j] = start;
					if (i - start >= 2)
					{
						in_col_word[k][j] = 1;
					}
				}
				if (i - start >= 2)
				{
					words++;
				}
			}
		}
	}
	return words;
}

/* 1 IF THE LETTER JUST PUT IN CELL (I, J) KEEPS ITS ROW WORD AND ITS COLUMN WORD CORRECT */
int letter_fits(int i, int j)
{
	char ch = grid[i][j];
	int t, run;

	if (in_row_word[i][j] == 1)
	{
		if (j > row_start[i][j] && grid[i][j - 1] == ch)
		{
			return 0; /* TWO EQUAL LETTERS SIDE BY SIDE */
		}
		/* THE LETTERS OF THE SAME KIND (VOWELS OR CONSONANTS) THAT END IN THIS CELL */
		run = 0;
		t = j;
		while (t >= row_start[i][j] && is_vowel(grid[i][t]) == is_vowel(ch))
		{
			run++;
			t--;
		}
		if (run_too_long(ch, run) == 1)
		{
			return 0;
		}
	}
	if (in_col_word[i][j] == 1)
	{
		if (i > col_start[i][j] && grid[i - 1][j] == ch)
		{
			return 0;
		}
		run = 0;
		t = i;
		while (t >= col_start[i][j] && is_vowel(grid[t][j]) == is_vowel(ch))
		{
			run++;
			t--;
		}
		if (run_too_long(ch, run) == 1)
		{
			return 0;
		}
	}
	return 1;
}

/* GENDER OF THE ROW WORD THAT ENDS IN CELL (I, J), OR -1 IF NO ROW WORD ENDS THERE */
int row_word_ending(int i, int j)
{
	if (in_row_word[i][j] == 1 && (j == n - 1 || black[i][j + 1] == 1))
	{
		return gender(grid[i][row_start[i][j]], grid[i][j]);
	}
	return -1;
}

/* GENDER OF THE COLUMN WORD THAT ENDS IN CELL (I, J), OR -1 IF NO COLUMN WORD ENDS THERE */
int col_word_ending(int i, int j)
{
	if (in_col_word[i][j] == 1 && (i == n - 1 || black[i + 1][j] == 1))
	{
		return gender(grid[col_start[i][j]][j], grid[i][j]);
	}
	return -1;
}

/* KEEPS A COPY OF THE CURRENT GRID AS THE BEST ONE */
void save_grid(void)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			best_grid[i][j] = grid[i][j];
		}
	}
}

/* FILLS THE CELLS FROM POSITION POS ON (POSITION = ROW * N + COLUMN);
 * SCORE IS THE WEIGHT OF THE COLUMN WORD LETTERS ALREADY PLACED */
void fill(int pos, int score)
{
	int i, j, k, g_row, g_col, gain;

	/* EVEN THE HEAVIEST LETTER IN EVERY COLUMN WORD CELL LEFT WOULD NOT BEAT THE BEST GRID */
	if (score + weight[0] * col_cells_left[pos] <= best_weight)
	{
		return;
	}
	if (pos == n * n)
	{
		if (have[0] == need[0] && have[1] == need[1] && have[2] == need[2])
		{
			best_weight = score; /* A COMPLETE GRID, BETTER THAN ALL BEFORE IT */
			save_grid();
		}
		return;
	}
	i = pos / n;
	j = pos % n;
	if (black[i][j] == 1)
	{
		fill(pos + 1, score);
		return;
	}
	for (k = 0; k < letters; k++)
	{
		grid[i][j] = letter[k];
		if (letter_fits(i, j) == 1)
		{
			/* A WORD THAT ENDS IN THIS CELL IS COMPLETE: COUNT ITS GENDER */
			g_row = row_word_ending(i, j);
			g_col = col_word_ending(i, j);
			if (g_row >= 0)
			{
				have[g_row]++;
			}
			if (g_col >= 0)
			{
				have[g_col]++;
			}
			/* GO ON ONLY IF NO GENDER HAS MORE WORDS THAN WANTED */
			if (have[0] <= need[0] && have[1] <= need[1] && have[2] <= need[2])
			{
				gain = 0;
				if (in_col_word[i][j] == 1)
				{
					gain = weight[k];
				}
				fill(pos + 1, score + gain);
			}
			if (g_row >= 0)
			{
				have[g_row]--;
			}
			if (g_col >= 0)
			{
				have[g_col]--;
			}
		}
	}
}

/* SORTS THE LETTERS FROM THE HEAVIEST TO THE LIGHTEST, SO THAT GOOD GRIDS ARE FOUND EARLY */
void sort_letters(void)
{
	int i, j, temp_weight;
	char temp_letter;

	for (i = 0; i < letters - 1; i++)
	{
		for (j = 0; j < letters - 1 - i; j++)
		{
			if (weight[j] < weight[j + 1])
			{
				temp_weight = weight[j];
				weight[j] = weight[j + 1];
				weight[j + 1] = temp_weight;
				temp_letter = letter[j];
				letter[j] = letter[j + 1];
				letter[j + 1] = temp_letter;
			}
		}
	}
}

/* PUTS IN NUMBER ALL THE NATURAL NUMBERS WRITTEN ON A LINE; RETURNS HOW MANY THERE ARE */
int read_numbers(char line[], int number[])
{
	int i, count = 0, value = 0, inside = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			value = value * 10 + (line[i] - '0');
			inside = 1;
		}
		else if (inside == 1)
		{
			number[count] = value; /* A NUMBER HAS JUST ENDED */
			count++;
			value = 0;
			inside = 0;
		}
	}
	if (inside == 1)
	{
		number[count] = value;
		count++;
	}
	return count;
}

/* WRITES THE BEST GRID AND ITS WEIGHT, OR THAT NO GRID RESPECTS THE RULES */
void write_result(FILE *out)
{
	int i, j;

	if (best_weight < 0)
	{
		fprintf(out, "Not possible\n");
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (black[i][j] == 1)
			{
				fprintf(out, "*");
			}
			else
			{
				fprintf(out, "%c", best_grid[i][j]);
			}
		}
		fprintf(out, "\n");
	}
	fprintf(out, "%d\n", best_weight);
}

int main(void)
{
	FILE *in;
	FILE *out;
	char name[100] = "";
	char line[MAXLINE] = "";
	int number[MAXLINE];
	int count, k, words;
	int w = 0;
	char ch = ' ';

	printf("Input file name: ");
	scanf("%99s", name);
	in = fopen(name, "r");
	if (in == NULL)
	{
		printf("Cannot open %s\n", name);
		return 1;
	}

	/* LINE 1: N, X, Y */
	fgets(line, MAXLINE, in);
	sscanf(line, "%d %d %d", &n, &x, &y);
	/* LINE 2: THE ROW AND THE COLUMN (FROM 1) OF EVERY BLACK CELL */
	fgets(line, MAXLINE, in);
	count = read_numbers(line, number);
	for (k = 0; k + 1 < count; k = k + 2)
	{
		black[number[k] - 1][number[k + 1] - 1] = 1;
	}
	/* LINE 3: HOW MANY MASCULINE, FEMININE AND NEUTER WORDS */
	fgets(line, MAXLINE, in);
	sscanf(line, "%d %d %d", &need[0], &need[1], &need[2]);
	/* THE OTHER LINES: A WEIGHT AND A LETTER */
	letters = 0;
	while (letters < MAXLETTERS && fscanf(in, "%d %c", &w, &ch) == 2)
	{
		weight[letters] = w;
		letter[letters] = ch;
		letters++;
	}
	fclose(in);

	sort_letters();
	words = find_row_words() + find_col_words();
	for (k = n * n - 1; k >= 0; k--)
	{
		col_cells_left[k] = col_cells_left[k + 1] + in_col_word[k / n][k % n];
	}
	/* THE NUMBER OF WORDS DEPENDS ONLY ON THE BLACK CELLS: IT MUST BE THE NUMBER WANTED */
	if (words == need[0] + need[1] + need[2])
	{
		fill(0, 0);
	}

	out = fopen("CNI.OUT", "w");
	write_result(out);
	fclose(out);

	return 0;
}
