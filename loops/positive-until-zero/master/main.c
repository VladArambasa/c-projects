/* PRINT THE POSITIVE ELEMENTS UNTIL THE FIRST 0: CONTINUE SKIPS, BREAK STOPS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int t[10] = {5, -2, 8, -1, 3, 0, 7, 9, -4, 6};
	int i;

	for (i = 0; i < 10; i++)
	{
		if (t[i] < 0)
		{
			continue; /* NEGATIVE: SKIP IT */
		}
		if (t[i] == 0)
		{
			break; /* ZERO: STOP */
		}
		printf("%d ", t[i]);
	}
	printf("\n");

	return 0;
}
