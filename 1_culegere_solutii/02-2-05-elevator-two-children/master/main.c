/* CULEGERE II.2.5 - ELEVATOR FOR TWO CHILDREN
 * A CHILDREN'S ELEVATOR CARRIES AT MOST 100 KG. READ THE WEIGHTS OF TWO CHILDREN AND PRINT
 * "BOTH CHILDREN CAN GO IN" OR "THEY GO IN ONE AT A TIME"
 * EXAMPLES: 87 50 -> THEY GO IN ONE AT A TIME; 45 52 -> BOTH CHILDREN CAN GO IN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int w1 = 0, w2 = 0;

	printf("Weights of the two children: ");
	scanf("%d %d", &w1, &w2);

	if (w1 + w2 <= 100) /* TOGETHER THEY MUST NOT GO OVER 100 KG */
	{
		printf("Both children can go in\n");
	}
	else
	{
		printf("They go in one at a time\n");
	}

	return 0;
}
