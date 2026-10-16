/* CULEGERE VI.2.5 - THE TELEPORTERS
 * CAPTAIN JACK O'NEEL IS IN ROOM 1 OF A SPACESHIP WITH N ROOMS IN A ROW. THE TELEPORTER OF EVERY
 * ROOM SENDS HIM TO A CERTAIN ROOM. CAN HE GET TO ROOM H? PRINT "YES" AND THE ROOMS HE PASSED
 * THROUGH, OR "NO". IF HE GETS INTO THE SAME ROOM TWICE, HE GIVES UP AND THE ANSWER IS "NO"
 * EXAMPLES: N=5 H=4, 2 3 4 1 3 -> YES 1 2 3 4;  N=4 H=4, 1 2 3 4 -> NO */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int t[MAX + 1] = {0};       /* T[R] = THE ROOM WHERE THE TELEPORTER OF ROOM R SENDS HIM */
	int visited[MAX + 1] = {0}; /* VISITED[R] = 1 IF HE WAS ALREADY IN ROOM R */
	int path[MAX + 1] = {0};    /* THE ROOMS HE PASSED THROUGH, IN ORDER */
	int n = 0, h = 0, i, room, steps;

	printf("n and h: ");
	scanf("%d %d", &n, &h);
	printf("The %d teleporters: ", n);
	for (i = 1; i <= n; i++) /* ROOMS ARE NUMBERED FROM 1, SO T[0] IS NOT USED */
	{
		scanf("%d", &t[i]);
	}

	room = 1; /* HE STARTS IN ROOM 1 */
	visited[1] = 1;
	path[0] = 1;
	steps = 1;
	while (room != h && visited[t[room]] == 0) /* GO ON WHILE THE NEXT ROOM IS A NEW ONE */
	{
		room = t[room];
		visited[room] = 1;
		path[steps] = room;
		steps++;
	}

	if (room == h)
	{
		printf("YES");
		for (i = 0; i < steps; i++)
		{
			printf(" %d", path[i]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n"); /* THE NEXT ROOM WAS ALREADY VISITED */
	}

	return 0;
}
