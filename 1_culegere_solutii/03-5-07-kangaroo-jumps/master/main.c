/* CULEGERE III.5.7 - THE KANGAROO'S JUMPS
 * A KANGAROO JUMPS 7 M ON THE FIRST DAY. EVERY NEXT DAY IT JUMPS 7 M MORE THAN TEN TIMES THE JUMP
 * OF THE DAY BEFORE: 7, 77, 777, ... PRINT HOW MANY METRES IT JUMPS IN TOTAL IN N DAYS
 * (ONI FOCSANI 2003, GRADE 5)
 * ASSUMPTION: N <= 19, SO THAT THE TOTAL FITS IN A LONG LONG
 * EXAMPLE: N=3 -> 861 M (7 + 77 + 777) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, day;
	long long jump, total; /* THE JUMPS GET 10 TIMES LONGER EVERY DAY, AN INT IS TOO SMALL */

	printf("n = ");
	scanf("%d", &n);

	jump = 0;
	total = 0;
	for (day = 1; day <= n; day++)
	{
		jump = 7 + 10 * jump; /* 7 MORE THAN TEN TIMES YESTERDAY: 7, 77, 777, ... */
		total = total + jump;
	}
	printf("%lld m\n", total);

	return 0;
}
