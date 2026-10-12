/* CULEGERE VI.2.4 - THE FIRST SPACE
 * N CHARACTERS ARE READ ONE AFTER THE OTHER; PRINT THE POSITION WHERE THE SPACE CHARACTER
 * APPEARS FOR THE FIRST TIME
 * EXAMPLE: N=10, THE CHARACTERS I N F O, SPACE, C L U B 7 -> 5
 * ASSUMPTION: THE N CHARACTERS ARE TYPED ON ONE LINE; WITHOUT ANY SPACE A MESSAGE IS PRINTED */
#include <stdio.h> /* PRINTF, SCANF, GETCHAR */

#define MAX 100

int main(void)
{
	char c[MAX] = {0};
	int n = 0, i;

	printf("n = ");
	scanf("%d", &n);
	getchar(); /* SKIP THE ENTER TYPED AFTER N */

	printf("The %d characters, all on one line (spaces count): ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%c", &c[i]); /* WITHOUT A SPACE BEFORE %C, SPACES ARE READ TOO */
	}

	i = 0;
	while (i < n && c[i] != ' ') /* WALK UNTIL THE FIRST SPACE OR THE END */
	{
		i++;
	}

	if (i < n)
	{
		printf("%d\n", i + 1); /* POSITIONS ARE COUNTED FROM 1 */
	}
	else
	{
		printf("No space\n");
	}

	return 0;
}
