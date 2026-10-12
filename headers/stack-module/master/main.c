/* STACK MODULE: MAIN.C USES THE STACK ONLY THROUGH THE FUNCTIONS IN STACK.H
 * LAST IN, FIRST OUT: THE NUMBERS COME BACK IN REVERSE ORDER */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0;

	printf("Enter up to %d numbers (Ctrl+D to finish): ", STACK_SIZE);
	while (!is_full() && scanf("%d", &x) == 1)
	{
		push(x);
	}

	printf("\nIn reverse order:");
	while (!is_empty())
	{
		printf(" %d", pop());
	}
	printf("\n");

	return 0;
}
