/* CULEGERE III.9.10 - PRIZES AT THE CONTEST
 * EVERY PAPER HAS A 3-DIGIT CODE ABC: A = THE CITY, B = THE SCHOOL IN THAT CITY, C = THE PUPIL
 * IN THAT SCHOOL. THE CODE OF OUR FRIEND H IS READ, THEN N AND THE N CODES OF THE PRIZES.
 * A) DID H WIN A PRIZE?  B) HOW MANY PRIZES WENT TO H'S CITY?  C) HOW MANY TO H'S SCHOOL?
 * ASSUMPTION: THE N CODES ARE THE CODES OF THE PRIZE-WINNING PAPERS
 * EXAMPLE: H=123, N=4: 133 221 123 125 -> A) YES  B) 3  C) 2 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int h = 0, n = 0, code = 0, i;
	int winner = 0; /* BECOMES 1 IF H'S CODE IS AMONG THE PRIZES */
	int city = 0;   /* PRIZES IN H'S CITY */
	int school = 0; /* PRIZES IN H'S SCHOOL */

	printf("Code of H: ");
	scanf("%d", &h);
	printf("n = ");
	scanf("%d", &n);

	printf("The %d codes: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &code);
		if (code == h)
		{
			winner = 1;
		}
		if (code / 100 == h / 100) /* SAME FIRST DIGIT: THE SAME CITY */
		{
			city++;
		}
		if (code / 10 == h / 10) /* SAME FIRST TWO DIGITS: SAME SCHOOL, SAME CITY */
		{
			school++;
		}
	}

	if (winner == 1)
	{
		printf("a) Yes\n");
	}
	else
	{
		printf("a) No\n");
	}
	printf("b) %d\n", city);
	printf("c) %d\n", school);

	return 0;
}
