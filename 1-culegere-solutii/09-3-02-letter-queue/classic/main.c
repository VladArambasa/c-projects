/* CULEGERE IX.3.2 - A QUEUE OF LETTERS
 * THE QUEUE HOLDS P A S C A L (P IS THE FRONT, L THE END). SHOW THE EFFECT OF THESE OPERATIONS:
 * EXTRACT, EXTRACT, INSERT C, EXTRACT, INSERT U, INSERT L (THE QUEUE IS PRINTED AFTER EVERY ONE)
 * EXAMPLE: (NO INPUT) -> A S C A L / S C A L / S C A L C / C A L C / C A L C U / C A L C U L
 * THE QUEUE IS ALLOCATED STATICALLY: AN ARRAY WITH THE POSITION OF THE FRONT AND OF THE END */
#include <stdio.h> /* PRINTF */

#define MAX 20 /* ROOM FOR 20 INSERTED LETTERS */

char queue[MAX];
int head = 0; /* THE POSITION OF THE FIRST LETTER */
int tail = 0; /* THE POSITION RIGHT AFTER THE LAST LETTER */

/* PRINTS THE QUEUE FROM THE FRONT TO THE END */
void print_queue(void)
{
	int i;

	printf("queue:");
	for (i = head; i < tail; i++)
	{
		printf(" %c", queue[i]);
	}
	printf("\n");
}

/* A NEW LETTER JOINS THE QUEUE AT THE END */
void insert(char letter)
{
	queue[tail] = letter;
	tail++;
	printf("insert %c  -> ", letter);
	print_queue();
}

/* THE LETTER AT THE FRONT LEAVES THE QUEUE */
void extract(void)
{
	printf("extract %c -> ", queue[head]);
	head++;
	print_queue();
}

int main(void)
{
	char start[] = "PASCAL";
	int i;

	for (i = 0; start[i] != '\0'; i++)
	{
		queue[tail] = start[i]; /* THE STARTING QUEUE, WITH P AT THE FRONT */
		tail++;
	}
	printf("start     -> ");
	print_queue();

	extract();
	extract();
	insert('C');
	extract();
	insert('U');
	insert('L');

	return 0;
}
