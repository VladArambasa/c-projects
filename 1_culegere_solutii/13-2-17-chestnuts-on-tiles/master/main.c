/* CULEGERE XIII.2.17 - CHESTNUTS ON TILES
 * 12 TILES IN 4 ROWS AND 3 COLUMNS HOLD CHESTNUTS (THE NUMBERS ARE READ ROW BY ROW). THE CHILD
 * STARTS ON THE FIRST TILE, WHICH HAS NO CHESTNUTS, AND MAKES K MOVES: A = THE ROW ABOVE,
 * B = THE NEXT COLUMN, C = THE ROW BELOW, D = THE PREVIOUS COLUMN, GATHERING THE CHESTNUTS OF EVERY
 * TILE HE REACHES. A) PRINT HOW MANY CHESTNUTS HE HAS AFTER EACH MOVE  B) ADD THE DIGITS OF THE
 * FINAL NUMBER AGAIN AND AGAIN UNTIL ONE DIGIT IS LEFT (173 -> 11 -> 2, 8 -> 8)
 * EXAMPLE: 0 5 7 3 1 2 10 8 4 6 1 1, K = 4, MOVES B C B C -> 5 6 8 12, THEN 12 -> 3
 * ASSUMPTION: THE CHESTNUTS OF A TILE ARE GATHERED ONLY ONCE; A TILE REACHED AGAIN IS EMPTY */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define ROWS 4
#define COLS 3

/* SUM OF THE DIGITS OF N */
int digit_sum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}

/* PRINTS N, THEN THE SUM OF ITS DIGITS, AGAIN AND AGAIN, UNTIL ONE DIGIT IS LEFT */
void print_digit_chain(int n)
{
	printf("%d", n);
	do
	{
		n = digit_sum(n);
		printf(" -> %d", n);
	} while (n > 9);
	printf("\n");
}

int main(void)
{
	int tile[ROWS][COLS];
	int i, j, k = 0, row = 0, col = 0, total = 0;
	char move = ' ';

	printf("The 12 numbers, row by row: ");
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			tile[i][j] = 0;
			scanf("%d", &tile[i][j]);
		}
	}
	printf("k = ");
	scanf("%d", &k);

	/* A) THE CHILD STANDS ON THE FIRST TILE (ROW 0, COLUMN 0) AND HAS NO CHESTNUTS YET */
	for (i = 1; i <= k; i++)
	{
		printf("Move %d (A/B/C/D): ", i);
		scanf(" %c", &move);
		if (move == 'A')
		{
			row--;
		}
		else if (move == 'B')
		{
			col++;
		}
		else if (move == 'C')
		{
			row++;
		}
		else if (move == 'D')
		{
			col--;
		}
		total = total + tile[row][col]; /* GATHER THE CHESTNUTS OF THE NEW TILE */
		tile[row][col] = 0;             /* NOTHING IS LEFT ON IT */
		printf("%d\n", total);
	}

	/* B) THE DIGIT GAME WITH THE FINAL NUMBER OF CHESTNUTS */
	print_digit_chain(total);

	return 0;
}
