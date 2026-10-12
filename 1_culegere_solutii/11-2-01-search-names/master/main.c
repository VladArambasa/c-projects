/* CULEGERE XI.2.1 - SEARCH NAMES IN A LIST
 * CHECK WHETHER EACH OF K STUDENT NAMES IS IN A LIST OF N NAMES, USING A FUNCTION SEARCH
 * (THE BOOK'S CAUTARE)
 * EXAMPLE: LIST ANA DAN ION MARIA; NAMES DAN AND VLAD -> DAN: YES, VLAD: NO
 * ASSUMPTION: EVERY NAME IS ONE WORD (NO SPACES) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* MOST NAMES IN THE LIST */
#define LEN 30 /* LONGEST NAME + 1 */

/* THE FUNCTION: 1 IF NAME IS ONE OF THE N NAMES OF THE LIST, 0 OTHERWISE */
int search(char list[][LEN], int n, char name[])
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (strcmp(list[i], name) == 0) /* STRCMP GIVES 0 FOR EQUAL TEXTS */
		{
			return 1; /* FOUND: NO NEED TO LOOK FURTHER */
		}
	}
	return 0;
}

int main(void)
{
	char list[MAX][LEN];
	char name[LEN] = "";
	int n = 0, k = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d names of the list: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%29s", list[i]);
	}

	printf("k = ");
	scanf("%d", &k);
	for (i = 1; i <= k; i++)
	{
		printf("Name %d: ", i);
		scanf("%29s", name);
		if (search(list, n, name) == 1)
		{
			printf("%s: Yes\n", name);
		}
		else
		{
			printf("%s: No\n", name);
		}
	}

	return 0;
}
