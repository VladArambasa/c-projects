/* CULEGERE VI.6.3 - LAST POSITION OF X
 * THE COMPUTER GENERATES N RANDOM INTEGERS FROM 0 TO 100. SEARCH FOR A NUMBER X AMONG THEM:
 * IF IT IS FOUND, PRINT THE LAST POSITION WHERE IT APPEARS, OTHERWISE "NUMBER NOT FOUND"
 * ASSUMPTION: THE GENERATED NUMBERS ARE SHOWN BEFORE X IS READ; POSITIONS ARE COUNTED FROM 1
 * EXAMPLE (NOT IN THE BOOK): GENERATED 7 42 7 15, X=7 -> LAST POSITION: 3 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 NUMBERS */

int main(void)
{
	int a[MAX];
	int n = 0, x = 0, i, pos;

	srand(time(NULL)); /* THE CLOCK MAKES EVERY RUN GENERATE OTHER NUMBERS */

	printf("n = ");
	scanf("%d", &n);
	printf("The generated numbers: ");
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 101; /* A REMAINDER BY 101 IS BETWEEN 0 AND 100 */
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("x = ");
	scanf("%d", &x);

	pos = 0; /* 0 MEANS NOT FOUND, BECAUSE REAL POSITIONS START AT 1 */
	for (i = 0; i < n; i++)
	{
		if (a[i] == x) /* EVERY MATCH REPLACES THE PREVIOUS ONE, SO THE LAST MATCH STAYS */
		{
			pos = i + 1;
		}
	}

	if (pos == 0)
	{
		printf("Number not found\n");
	}
	else
	{
		printf("Last position: %d\n", pos);
	}

	return 0;
}
