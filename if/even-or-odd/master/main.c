/* EVEN OR ODD */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	if (n % 2 == 0) /* NO REMAINDER WHEN DIVIDED BY 2 */
	{
		printf("%d is even\n", n);
	}
	else
	{
		printf("%d is odd\n", n);
	}

	return 0;
}
