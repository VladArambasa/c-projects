/* CULEGERE III.5.4 - GROWING TREE
 * A TREE IS 1 M TALL WHEN IT IS PLANTED AND GROWS 0.75 CM EVERY DAY. PRINT AFTER HOW MANY DAYS
 * IT REACHES 12 M AND HOW TALL IT IS AFTER ONE MONTH (30 DAYS)
 * EXAMPLE: NO INPUT -> 12 M AFTER 1467 DAYS; 122.50 CM AFTER 30 DAYS */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int days;
	double height;

	/* ALL HEIGHTS ARE IN CM: 1 M = 100 CM, 12 M = 1200 CM */
	height = 100;
	days = 0;
	while (height < 1200) /* ONE MORE DAY OF GROWTH WHILE THE TREE IS SHORTER THAN 12 M */
	{
		height = height + 0.75;
		days++;
	}
	printf("The tree reaches 12 m after %d days\n", days);

	/* START AGAIN FROM 1 M AND REPEAT THE GROWTH OF ONE DAY 30 TIMES */
	height = 100;
	for (days = 1; days <= 30; days++)
	{
		height = height + 0.75;
	}
	printf("After 30 days it is %.2f cm tall\n", height);

	return 0;
}
