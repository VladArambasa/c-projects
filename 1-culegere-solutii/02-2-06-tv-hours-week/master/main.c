/* CULEGERE II.2.6 - TV HOURS IN A WEEK
 * IONEL MAY WATCH TV 20 HOURS A WEEK. READ THE HOURS HE WATCHED ON EACH DAY OF THE WEEK AND
 * CHECK WHETHER HE WILL BE PUNISHED
 * EXAMPLE: 3 4 2 2 5 6 1 -> HE WILL BE PUNISHED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, total;

	printf("Hours for each of the 7 days: ");
	scanf("%d %d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6, &d7);

	total = d1 + d2 + d3 + d4 + d5 + d6 + d7; /* HOURS IN THE WHOLE WEEK */

	if (total > 20) /* MORE THAN HE IS ALLOWED */
	{
		printf("He will be punished\n");
	}
	else
	{
		printf("He will not be punished\n");
	}

	return 0;
}
