/* CULEGERE XIII.1.13 - PINOCCHIO'S NOSE (V1)
 * FROM MONDAY TO FRIDAY PINOCCHIO TELLS A LIE EVERY DAY AND HIS NOSE GROWS BY P CM; ON SATURDAY AND
 * SUNDAY HE TELLS NO LIES AND HIS NOSE GETS 1 CM SHORTER EACH DAY; AT FIRST THE NOSE IS N CM LONG
 * HOW LONG IS IT AFTER K DAYS, IF THE FIRST DAY IS A MONDAY?
 * EXAMPLE: N=2 P=1 K=8 -> 6 CM
 * V1: GO THROUGH THE DAYS ONE BY ONE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, p = 0, k = 0, day, length;

	printf("n = ");
	scanf("%d", &n);
	printf("p = ");
	scanf("%d", &p);
	printf("k = ");
	scanf("%d", &k);

	length = n;
	for (day = 1; day <= k; day++)
	{
		/* DAY 1 IS A MONDAY, SO DAYS 6, 13, 20, ... ARE SATURDAYS
		 * AND DAYS 7, 14, 21, ... ARE SUNDAYS (DAY % 7 IS 6 OR 0) */
		if (day % 7 == 6 || day % 7 == 0)
		{
			length = length - 1;
		}
		else
		{
			length = length + p;
		}
	}
	printf("%d cm\n", length);

	return 0;
}
