/* CULEGERE VII.1.6 - KNIGHT MOVES
 * AN 8 X 8 TABLE IS A CHESS BOARD; THE ROW AND THE COLUMN OF A KNIGHT ARE READ (FROM 1 TO 8);
 * PRINT THE SQUARES OF THE BOARD WHERE THE KNIGHT CAN JUMP
 * EXAMPLE: 2 2 -> 1 4   4 1   4 3   3 4 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	/* THE 8 JUMPS OF A KNIGHT AS (ROW CHANGE, COLUMN CHANGE), GOING AROUND THE KNIGHT
	 * COUNTERCLOCKWISE; THIS FIXED ORDER GIVES THE ORDER OF THE BOOK'S EXAMPLE */
	int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int dc[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int row = 0, col = 0, k, r, c;

	printf("Row and column of the knight: ");
	scanf("%d %d", &row, &col);

	printf("The knight can jump to:");
	for (k = 0; k < 8; k++)
	{
		r = row + dr[k];
		c = col + dc[k];
		/* THE JUMP IS POSSIBLE ONLY IF THE KNIGHT STAYS ON THE BOARD */
		if (r >= 1 && r <= 8 && c >= 1 && c <= 8)
		{
			printf(" %d %d  ", r, c);
		}
	}
	printf("\n");

	return 0;
}
