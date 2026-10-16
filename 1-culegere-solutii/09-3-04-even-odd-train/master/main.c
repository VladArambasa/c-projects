/* CULEGERE IX.3.4 - EVEN WAGONS FIRST, ODD WAGONS LAST
 * THE SAME DEPOT AS IN THE PREVIOUS PROBLEM (A DEAD END, SO A STACK; WAGONS 1..N COME FROM
 * THE RIGHT IN INCREASING ORDER). BUILD A TRAIN WITH THE EVEN WAGONS FIRST, IN INCREASING ORDER,
 * AND THE ODD WAGONS AT THE END, IN DECREASING ORDER; PRINT EVERY MOVE
 * ASSUMPTION: EVERY WAGON PASSES THROUGH THE DEPOT; THE TRAIN IS MADE OF THE WAGONS IN THE ORDER IN
 * WHICH THEY LEAVE THE DEPOT
 * EXAMPLE: N = 6 -> TRAIN: 2 4 6 5 3 1
 * IDEA: AN EVEN WAGON ENTERS AND LEAVES AT ONCE; THE ODD ONES WAIT, THEN LEAVE REVERSED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 WAGONS */

int depot[MAX]; /* THE STACK: DEPOT[0] IS THE WAGON DEEPEST INSIDE */
int top = 0;    /* HOW MANY WAGONS ARE IN THE DEPOT */
int train[MAX]; /* THE WAGONS IN THE ORDER IN WHICH THEY LEFT THE DEPOT */
int length = 0; /* HOW MANY WAGONS THE TRAIN HAS */

/* PRINTS THE WAGONS IN THE DEPOT, FROM THE DEEPEST ONE TO THE EXIT */
void print_depot(void)
{
	int i;

	printf(" -> depot:");
	if (top == 0)
	{
		printf(" empty");
	}
	for (i = 0; i < top; i++)
	{
		printf(" %d", depot[i]);
	}
	printf("\n");
}

/* PUSH: THE WAGON ENTERS THE DEPOT AND STAYS ON TOP OF THE OTHERS */
void enter(int wagon)
{
	depot[top] = wagon;
	top++;
	printf("wagon %d enters the depot", wagon);
	print_depot();
}

/* POP: ONLY THE LAST WAGON THAT ENTERED CAN LEAVE; IT IS ADDED TO THE TRAIN */
void leave(void)
{
	top--;
	train[length] = depot[top];
	length++;
	printf("wagon %d leaves the depot", depot[top]);
	print_depot();
}

int main(void)
{
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		enter(i);
		if (i % 2 == 0)
		{
			leave(); /* AN EVEN WAGON GOES STRAIGHT ON TO THE TRAIN */
		}
	}
	while (top > 0)
	{
		leave(); /* THE ODD WAGONS LEAVE IN REVERSE ORDER: ..., 5, 3, 1 */
	}

	printf("train:");
	for (i = 0; i < length; i++)
	{
		printf(" %d", train[i]);
	}
	printf("\n");

	return 0;
}
