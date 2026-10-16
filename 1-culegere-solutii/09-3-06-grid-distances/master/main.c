/* CULEGERE IX.3.6 - DISTANCES ON A GRID
 * A GRID HAS N ROWS AND M COLUMNS, WITH OBSTACLES ON SOME CELLS; A MOBILE STARTS AT (X0, Y0) AND
 * MOVES ONE CELL UP, DOWN, LEFT OR RIGHT AT A TIME. PRINT, FOR EVERY CELL, THE SMALLEST NUMBER OF
 * MOVES NEEDED TO REACH IT FROM THE START (-1 = OBSTACLE, -2 = A CELL THAT CANNOT BE REACHED)
 * EXAMPLE: N = 5, M = 5, START 3 3, OBSTACLES 1 2, 1 3, 2 4, 4 3, 4 4, 2 1 ->
 *          -2 -1 -1 5 4 / -1 2 1 -1 3 / 2 1 0 1 2 / 3 2 -1 -1 3 / 4 3 4 5 4
 * IDEA (LEE'S ALGORITHM): THE CELLS LEAVE A QUEUE IN THE ORDER OF THEIR DISTANCE; EVERY FREE
 * NEIGHBOUR NOT REACHED YET GETS THAT DISTANCE + 1 AND JOINS THE END OF THE QUEUE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 ROWS AND 50 COLUMNS */

int main(void)
{
	int d[MAX + 1][MAX + 1];          /* THE DISTANCES; ROWS AND COLUMNS START FROM 1 */
	int qx[MAX * MAX], qy[MAX * MAX]; /* THE QUEUE OF CELLS: ROW AND COLUMN */
	int dx[4] = {-1, 1, 0, 0};        /* THE 4 MOVES: UP, DOWN, LEFT, RIGHT */
	int dy[4] = {0, 0, -1, 1};
	int n = 0, m = 0, x0 = 0, y0 = 0, k = 0, x = 0, y = 0;
	int i, j, head, tail, nx, ny;

	printf("n (rows) = ");
	scanf("%d", &n);
	printf("m (columns) = ");
	scanf("%d", &m);
	printf("x0 (row) = ");
	scanf("%d", &x0);
	printf("y0 (column) = ");
	scanf("%d", &y0);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			d[i][j] = -2; /* NOT REACHED YET */
		}
	}
	printf("Number of obstacles: ");
	scanf("%d", &k);
	printf("The obstacles (row column): ");
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &x, &y);
		d[x][y] = -1;
	}

	d[x0][y0] = 0;
	head = 0;
	tail = 0;
	qx[tail] = x0; /* THE QUEUE STARTS WITH THE STARTING CELL */
	qy[tail] = y0;
	tail++;
	while (head < tail)
	{
		x = qx[head]; /* EXTRACT THE CELL AT THE FRONT */
		y = qy[head];
		head++;
		for (i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && d[nx][ny] == -2)
			{
				d[nx][ny] = d[x][y] + 1; /* ONE MOVE MORE THAN CELL (X, Y) */
				qx[tail] = nx;
				qy[tail] = ny;
				tail++;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%3d", d[i][j]);
		}
		printf("\n");
	}

	return 0;
}
