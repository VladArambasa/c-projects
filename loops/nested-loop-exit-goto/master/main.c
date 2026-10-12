/* GOTO: LEAVE TWO NESTED LOOPS IN ONE JUMP (USE IT RARELY) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int target = 0, i, j;

	printf("Enter a number: ");
	scanf("%d", &target);

	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (i * j == target)
			{
				goto found; /* BREAK WOULD LEAVE ONLY THE INNER LOOP */
			}
		}
	}
	printf("%d is not in the 9 x 9 multiplication table\n", target);
	return 0;

found: /* A LABEL: THE PLACE GOTO JUMPS TO */
	printf("%d = %d x %d\n", target, i, j);
	return 0;
}
