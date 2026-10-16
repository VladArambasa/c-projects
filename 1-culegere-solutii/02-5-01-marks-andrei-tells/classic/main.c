/* CULEGERE II.5.1 - MARKS ANDREI TELLS
 * ANDREI GETS THREE MARKS. IF THE LAST ONE IS AT LEAST 8 HE TELLS HIS PARENTS ALL THREE MARKS,
 * OTHERWISE ONLY THE BIGGER OF THE FIRST TWO. PRINT THE MARKS HE TELLS
 * EXAMPLES: 6 9 9 -> 6 9 9; 8 5 7 -> 8 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, c = 0;

	printf("The three marks: ");
	scanf("%d %d %d", &a, &b, &c);

	if (c >= 8) /* THE LAST MARK DECIDES */
	{
		printf("%d %d %d\n", a, b, c);
	}
	else if (a > b) /* ONLY THE BIGGER OF THE FIRST TWO */
	{
		printf("%d\n", a);
	}
	else
	{
		printf("%d\n", b);
	}

	return 0;
}
