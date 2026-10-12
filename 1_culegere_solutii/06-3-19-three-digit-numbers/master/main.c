/* CULEGERE VI.3.19 - THREE-DIGIT NUMBERS
 * N NATURAL NUMBERS ARE READ; HOW MANY OF THEM HAVE 3 DIGITS?
 * EXAMPLE (THE BOOK GIVES NONE): N=5, 7 100 999 1000 45 -> 2 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] >= 100 && a[i] <= 999) /* THE SMALLEST AND THE LARGEST 3-DIGIT NUMBERS */
		{
			count++;
		}
	}

	printf("Numbers with 3 digits: %d\n", count);

	return 0;
}
