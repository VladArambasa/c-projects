/* FOR AND WHILE ARE EQUIVALENT: THE SAME LOOP WRITTEN BOTH WAYS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int i;

	printf("for:   ");
	for (i = 1; i <= 5; i++) /* START; CONDITION; STEP ON ONE LINE */
	{
		printf("%d ", i);
	}
	printf("\n");

	printf("while: ");
	i = 1;          /* START */
	while (i <= 5)  /* CONDITION */
	{
		printf("%d ", i);
		i++;        /* STEP */
	}
	printf("\n");

	return 0;
}
