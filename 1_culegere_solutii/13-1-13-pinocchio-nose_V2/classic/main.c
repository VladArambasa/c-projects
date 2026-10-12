/* CULEGERE XIII.1.13 - PINOCCHIO'S NOSE (V2)
 * FROM MONDAY TO FRIDAY PINOCCHIO TELLS A LIE EVERY DAY AND HIS NOSE GROWS BY P CM; ON SATURDAY AND
 * SUNDAY HE TELLS NO LIES AND HIS NOSE GETS 1 CM SHORTER EACH DAY; AT FIRST THE NOSE IS N CM LONG
 * HOW LONG IS IT AFTER K DAYS, IF THE FIRST DAY IS A MONDAY?
 * EXAMPLE: N=2 P=1 K=8 -> 6 CM
 * V2: EVERY FULL WEEK ADDS 5 * P - 2 CM, SO ONLY THE DAYS AFTER THE LAST FULL WEEK ARE LEFT */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, p = 0, k = 0, weeks, rest, length;

	printf("n = ");
	scanf("%d", &n);
	printf("p = ");
	scanf("%d", &p);
	printf("k = ");
	scanf("%d", &k);

	weeks = k / 7; /* A FULL WEEK: 5 DAYS WITH LIES (+P EACH) AND A WEEKEND (-1 EACH) */
	rest = k % 7;  /* THE DAYS LEFT OVER, STARTING ON A MONDAY */
	length = n + weeks * (5 * p - 2);
	if (rest <= 5) /* ONLY WORKING DAYS */
	{
		length = length + rest * p;
	}
	else /* REST = 6: MONDAY TO FRIDAY, THEN A SATURDAY */
	{
		length = length + 5 * p - 1;
	}
	printf("%d cm\n", length);

	return 0;
}
