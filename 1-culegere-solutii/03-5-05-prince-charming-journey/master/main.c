/* CULEGERE III.5.5 - PRINCE CHARMING'S JOURNEY
 * TO FREE ILEANA COSANZEANA, FAT-FRUMOS MUST WALK X KM. EVERY DAY HE WALKS FORWARD, BUT EVERY
 * NIGHT THE WICKED FAIRY CARRIES HIM BACK: A = KM WALKED IN ONE DAY, B = KM LOST IN ONE NIGHT,
 * B < A. AFTER HOW MANY DAYS DOES HE FREE HER?
 * EXAMPLE: X=10 A=4 B=1 -> 3 DAYS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 0, a = 0, b = 0, distance, days;

	printf("x = ");
	scanf("%d", &x);
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	distance = a; /* HOW FAR HE IS AT THE END OF THE FIRST DAY */
	days = 1;
	while (distance < x) /* NOT THERE YET: A NIGHT AND ANOTHER DAY FOLLOW */
	{
		distance = distance - b; /* THE NIGHT TAKES HIM BACK */
		distance = distance + a; /* THE NEXT DAY HE WALKS AGAIN */
		days++;
	}
	printf("%d days\n", days);

	return 0;
}
