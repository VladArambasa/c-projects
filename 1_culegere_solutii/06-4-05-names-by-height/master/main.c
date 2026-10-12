/* CULEGERE VI.4.5 - NAMES BY HEIGHT
 * THE NAMES AND HEIGHTS OF N PUPILS ARE READ (N <= 100); PRINT THE NAMES IN DESCENDING ORDER
 * OF HEIGHT
 * ASSUMPTION: EVERY NAME IS ONE WORD OF AT MOST 30 LETTERS; EQUAL HEIGHTS KEEP THE INPUT ORDER
 * EXAMPLE: N=3, ION 120, ANA 114, DAN 130 -> DAN ION ANA */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* N <= 100 */

struct pupil
{
	char name[31]; /* 30 LETTERS AND THE FINAL '\0' */
	int height;
};

int main(void)
{
	struct pupil p[MAX], temp;
	int n = 0, i, j;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Name of pupil %d: ", i + 1);
		scanf("%30s", p[i].name);
		printf("Height of pupil %d: ", i + 1);
		scanf("%d", &p[i].height);
	}

	/* BUBBLE SORT BY HEIGHT, TALLEST FIRST. A WHOLE STRUCT IS SWAPPED AT ONCE, SO EVERY NAME
	 * STAYS WITH ITS HEIGHT. EQUAL HEIGHTS ARE NEVER SWAPPED, SO THEY KEEP THE INPUT ORDER */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (p[j].height < p[j + 1].height)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%s ", p[i].name);
	}
	printf("\n");

	return 0;
}
