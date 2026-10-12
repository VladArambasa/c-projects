/* CULEGERE II.1.6 - PREDECESSOR OR SUCCESSOR
 * READ TWO INTEGERS; CHECK WHETHER THE FIRST ONE IS THE PREDECESSOR (OR THE SUCCESSOR) OF THE
 * SECOND ONE AND PRINT A MESSAGE
 * EXAMPLES: 2 4 -> NO; 5 6 -> YES
 * ASSUMPTION: BOTH CASES ARE CHECKED AND THE MESSAGE SAYS WHICH ONE HOLDS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0;

	printf("The two numbers: ");
	scanf("%d %d", &a, &b);

	if (a + 1 == b) /* A COMES RIGHT BEFORE B */
	{
		printf("Yes, %d is the predecessor of %d\n", a, b);
	}
	else if (a - 1 == b) /* A COMES RIGHT AFTER B */
	{
		printf("Yes, %d is the successor of %d\n", a, b);
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
