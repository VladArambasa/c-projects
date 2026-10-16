/* CULEGERE VI.1.5 - NUMBERS DIVISIBLE BY D
 * READ N NUMBERS INTO A VECTOR AND A NUMBER D; PRINT THE NUMBERS OF THE SEQUENCE THAT ARE
 * DIVISIBLE BY D
 * EXAMPLE: N=5, 5 7 10 23 15, D=5 -> 5 10 15 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX] = {0};
	int n = 0, d = 0, i;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("d = ");
	scanf("%d", &d);

	for (i = 0; i < n; i++)
	{
		if (a[i] % d == 0) /* REMAINDER 0 MEANS DIVISIBLE */
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");

	return 0;
}
