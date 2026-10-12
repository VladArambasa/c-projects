/* FOR LOOP: REPEAT A KNOWN NUMBER OF TIMES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int i;

	for (i = 0; i < 5; i++) /* START; CONDITION; STEP */
	{
		printf("%d\n", i);
	}

	printf("Even numbers up to 10:");
	for (i = 0; i <= 10; i = i + 2) /* THE STEP CAN BE ANY VALUE */
	{
		printf(" %d", i);
	}
	printf("\n");

	return 0;
}
