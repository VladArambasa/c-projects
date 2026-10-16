/* CULEGERE VI.3.5 - MEN BETWEEN 50 AND 70
 * THE AGES OF N MEN ARE READ AND STORED; PRINT HOW MANY ARE OLDER THAN 50 AND YOUNGER THAN 70
 * EXAMPLE: N=4, 56 45 76 65 -> 2 MEN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int age[MAX] = {0};
	int n = 0, i;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d ages: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &age[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (age[i] > 50 && age[i] < 70) /* 50 AND 70 THEMSELVES DO NOT COUNT */
		{
			count++;
		}
	}

	printf("%d %s\n", count, (count == 1) ? "man" : "men");

	return 0;
}
