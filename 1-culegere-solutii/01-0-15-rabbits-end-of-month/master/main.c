/* CULEGERE I.15 - RABBITS AT THE END OF THE MONTH
 * READ THE NUMBER OF RABBITS AT THE START OF A MONTH, HOW MANY DIED AND HOW MANY WERE BORN
 * IN THAT MONTH; PRINT HOW MANY RABBITS THERE ARE AT THE END OF THE MONTH
 * EXAMPLE: 10 2 6 -> 14 RABBITS
 * ASSUMPTION: ONE RUN OF THE PROGRAM HANDLES ONE MONTH */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int start = 0, dead = 0, born = 0, end;

	printf("Rabbits at the start of the month: ");
	scanf("%d", &start);
	printf("Rabbits that died: ");
	scanf("%d", &dead);
	printf("Rabbits born: ");
	scanf("%d", &born);

	end = start - dead + born; /* THE DEAD ONES ARE GONE, THE NEWBORNS ARE ADDED */

	printf("%d rabbits\n", end);

	return 0;
}
