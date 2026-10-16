/* CULEGERE I.7 - APPLES OF TWO CHILDREN
 * TWO CHILDREN GOT THE SAME NUMBER OF APPLES. THE FIRST ONE EATS AN APPLE AND GIVES ONE TO THE
 * SECOND ONE. READ THE NUMBER OF APPLES AND PRINT HOW MANY APPLES EACH CHILD HAS NOW
 * EXAMPLE: 10 -> FIRST CHILD 8 APPLES, SECOND CHILD 11 APPLES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int apples = 0, first, second;

	printf("Apples received by each child: ");
	scanf("%d", &apples);

	first = apples - 2; /* ONE EATEN, ONE GIVEN AWAY */
	second = apples + 1; /* ONE RECEIVED FROM THE FIRST CHILD */

	printf("first child %d apples\n", first);
	printf("second child %d apples\n", second);

	return 0;
}
