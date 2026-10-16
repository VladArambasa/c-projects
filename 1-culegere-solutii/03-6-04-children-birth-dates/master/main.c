/* CULEGERE III.6.4 - BIRTH DATES
 * THE BIRTH DATES OF N CHILDREN ARE READ AS YEAR, MONTH, DAY; PRINT HOW MANY CHILDREN WERE
 * BORN ON JUNE 1 AND HOW MANY WERE BORN IN 1994, 1995 OR 1996
 * ASSUMPTION: THE SECOND ANSWER IS ONE COUNT FOR THE THREE YEARS TOGETHER, AS IN THE EXAMPLE
 * EXAMPLE: N=3: 1994 12 3, 1990 6 1, 1995 6 1 -> 2 CHILDREN BORN ON JUNE 1,
 *          2 CHILDREN BORN IN 1994, 1995 OR 1996 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, i;
	int year = 0, month = 0, day = 0;
	int june_1 = 0; /* CHILDREN BORN ON JUNE 1 */
	int years = 0;  /* CHILDREN BORN IN 1994, 1995 OR 1996 */

	printf("n = ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("Child %d (year month day): ", i);
		scanf("%d %d %d", &year, &month, &day);

		if (month == 6 && day == 1) /* JUNE IS MONTH 6 */
		{
			june_1++;
		}
		if (year >= 1994 && year <= 1996) /* ONE OF THE THREE YEARS */
		{
			years++;
		}
	}

	/* "CHILD" FOR 1, "CHILDREN" FOR ANY OTHER NUMBER */
	printf("%d %s born on June 1\n", june_1, (june_1 == 1) ? "child" : "children");
	printf("%d %s born in 1994, 1995 or 1996\n", years, (years == 1) ? "child" : "children");

	return 0;
}
