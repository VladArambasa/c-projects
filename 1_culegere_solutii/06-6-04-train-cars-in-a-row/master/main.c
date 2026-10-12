/* CULEGERE VI.6.4 - TRAIN CARS IN A ROW
 * A TRAIN HAS N CARS OF CLASS 1 OR 2, AND THE CHIEF WANTS AT MOST K CARS OF THE SAME CLASS ONE
 * AFTER ANOTHER. CHECK IF AN ARRANGEMENT HAS MORE THAN K CARS OF THE SAME CLASS IN A ROW; IF IT
 * HAS, ALSO PRINT THE STARTING POSITION OF EVERY SUCH GROUP
 * EXAMPLE: N=6, K=3, 1 1 2 2 2 2 -> YES, STARTING POSITION 3 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 CARS */

int main(void)
{
	int car[MAX], start[MAX];
	int n = 0, k = 0, count, i, j;

	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	printf("The classes of the %d cars (1 or 2): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &car[i]);
	}

	/* CUT THE TRAIN INTO GROUPS OF NEIGHBOUR CARS OF THE SAME CLASS */
	count = 0; /* HOW MANY GROUPS ARE TOO LONG */
	i = 0;     /* A GROUP STARTS AT INDEX I */
	while (i < n)
	{
		j = i;
		while (j < n && car[j] == car[i]) /* J STOPS AT THE FIRST CAR OF THE OTHER CLASS */
		{
			j++;
		}
		if (j - i > k) /* THE GROUP CAR[I..J-1] HAS J - I CARS */
		{
			start[count] = i + 1; /* POSITIONS ARE COUNTED FROM 1 */
			count++;
		}
		i = j; /* THE NEXT GROUP STARTS WHERE THIS ONE ENDED */
	}

	if (count == 0)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes, starting position");
		for (i = 0; i < count; i++)
		{
			printf(" %d", start[i]);
		}
		printf("\n");
	}

	return 0;
}
