/* CULEGERE X.2.3 - "DON'T GET UPSET, BROTHER!" (OJI 2004, CLASS VII)
 * A CIRCULAR TRACK HAS N CELLS (7 <= N <= 100) HOLDING 0, 1 OR 10; CELL 1 NEVER HOLDS 0. BOTH PAWNS
 * START ON CELL 1 AND THE PLAYERS MOVE IN TURN, PLAYER 1 FIRST, BY THE DIE VALUES OF JOC.IN. A PAWN
 * MOVES CLOCKWISE AS MANY CELLS AS THE DIE SHOWS. WHERE IT LANDS:
 * - ON CELL 1 AGAIN: THE PLAYER GETS THE POINTS OF CELL 1 AND WINS AT ONCE;
 * - ON A 0 CELL OR ON THE CELL OF THE OTHER PAWN: ITS POINTS ARE LOST, IT GOES BACK TO CELL 1;
 * - ON A 1 OR 10 CELL: THE PLAYER GETS 1 OR 10 POINTS.
 * IF THE THROWS END FIRST, MORE POINTS WIN; WITH EQUAL POINTS, THE PAWN ON THE HIGHER CELL WINS.
 * JOC.IN: N / THE N CELLS / THE NUMBER OF THROWS / THE THROWS (1..6)
 * JOC.OUT: THE WINNER / CELL AND POINTS OF PLAYER 1 / CELL AND POINTS OF PLAYER 2
 * ASSUMPTION: ONLY LANDING EXACTLY ON CELL 1 WINS (PASSING OVER IT DOES NOT), AS THE BOOK'S
 * EXAMPLES SHOW; IF THE POINTS AND THE CELLS ARE BOTH EQUAL (BOTH PAWNS ON CELL 1 WITH 0 POINTS)
 * NOBODY WINS AND THE WINNER IS WRITTEN AS 0
 * EXAMPLE: N = 10, CELLS 1 1 1 1 1 10 0 1 1 0, 8 THROWS 3 6 2 4 1 3 5 3 -> 2 / 6 10 / 1 3 */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF, FCLOSE */

#define MAXN 100 /* AT MOST 100 CELLS */

int main(void)
{
	FILE *in = fopen("JOC.IN", "r");
	FILE *out;
	int cell[MAXN + 1];
	int pos[3] = {0, 1, 1};    /* PAWN CELLS OF PLAYERS 1 AND 2 (POS[0] IS NOT USED) */
	int points[3] = {0, 0, 0}; /* THE POINTS OF PLAYERS 1 AND 2 */
	int n = 0, throws = 0, die = 0, i, player, other, winner = 0;

	if (in == NULL)
	{
		printf("Cannot open JOC.IN\n");
		return 1;
	}
	fscanf(in, "%d", &n);
	for (i = 1; i <= n; i++)
	{
		fscanf(in, "%d", &cell[i]);
	}
	fscanf(in, "%d", &throws);

	player = 1;
	i = 0;
	while (i < throws && winner == 0)
	{
		fscanf(in, "%d", &die);
		other = 3 - player; /* THE OTHER PLAYER: 1 BECOMES 2, 2 BECOMES 1 */
		/* MOVE CLOCKWISE; AFTER CELL N COMES CELL 1 */
		pos[player] = (pos[player] - 1 + die) % n + 1;

		/* A PAWN AWAY FROM CELL 1 ALWAYS HAS POINTS (ANY OTHER LANDING GIVES POINTS
		 * OR SENDS IT BACK), SO "EXCEPT WITH 0 POINTS" ONLY SAYS THAT A PAWN
		 * SENT BACK TO CELL 1 HAS NOT WON */
		if (pos[player] == 1)
		{
			points[player] = points[player] + cell[1];
			winner = player; /* A WIN, EVEN IF THE OTHER PAWN IS ON CELL 1 */
		}
		else if (cell[pos[player]] == 0 || pos[player] == pos[other])
		{
			points[player] = 0; /* PENALTY: ALL POINTS LOST, BACK TO THE START */
			pos[player] = 1;
		}
		else
		{
			points[player] = points[player] + cell[pos[player]];
		}
		player = other; /* NOW IT IS THE OTHER PLAYER'S TURN */
		i++;
	}
	fclose(in);

	if (winner == 0) /* THE THROWS ENDED: COMPARE THE POINTS, THEN THE CELLS */
	{
		if (points[1] > points[2] || (points[1] == points[2] && pos[1] > pos[2]))
		{
			winner = 1;
		}
		else if (points[2] > points[1] || (points[1] == points[2] && pos[2] > pos[1]))
		{
			winner = 2;
		}
	}

	out = fopen("JOC.OUT", "w");
	fprintf(out, "%d\n", winner);
	fprintf(out, "%d %d\n", pos[1], points[1]);
	fprintf(out, "%d %d\n", pos[2], points[2]);
	fclose(out);

	return 0;
}
