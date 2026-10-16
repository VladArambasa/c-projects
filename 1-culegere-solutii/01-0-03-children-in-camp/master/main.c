/* CULEGERE I.3 - CHILDREN IN THE CAMP
 * THERE ARE 10 MORE BOYS THAN GIRLS; READ THE NUMBER OF GIRLS, PRINT HOW MANY CHILDREN THERE ARE
 * EXAMPLE: 50 -> 110 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int girls = 0, boys;

	printf("Number of girls: ");
	scanf("%d", &girls);

	boys = girls + 10; /* 10 MORE BOYS THAN GIRLS */

	printf("%d children\n", girls + boys);

	return 0;
}
