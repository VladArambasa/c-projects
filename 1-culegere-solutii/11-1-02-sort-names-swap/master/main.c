/* CULEGERE XI.1.2 - SORT NAMES WITH A SWAP PROCEDURE
 * SORT N STUDENT NAMES IN ALPHABETICAL ORDER, USING A PROCEDURE WITH TWO PARAMETERS THAT SWAPS
 * THE VALUES OF TWO NAMES
 * EXAMPLE: MARIA ION ANA DAN -> ANA DAN ION MARIA
 * ASSUMPTION: EVERY NAME IS ONE WORD (NO SPACES) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* MOST NAMES */
#define LEN 30 /* LONGEST NAME + 1 */

/* THE PROCEDURE: SWAPS THE TEXTS OF TWO NAMES (AN ARRAY PARAMETER IS CHANGED IN PLACE) */
void swap_names(char a[], char b[])
{
	char temp[LEN];

	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

int main(void)
{
	char names[MAX][LEN];
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d names: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%29s", names[i]);
	}

	/* BUBBLE SORT: TWO NEIGHBOURS IN THE WRONG ORDER ARE SWAPPED */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			/* STRCMP > 0: NAMES[J] COMES LATER IN THE ALPHABET THAN NAMES[J + 1] */
			if (strcmp(names[j], names[j + 1]) > 0)
			{
				swap_names(names[j], names[j + 1]);
			}
		}
	}

	printf("Sorted names:\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", names[i]);
	}

	return 0;
}
