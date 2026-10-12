/* BREAK LEAVES THE LOOP, CONTINUE SKIPS TO THE NEXT ROUND */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int i;

	printf("break at 4:    ");
	for (i = 0; i < 10; i++)
	{
		if (i == 4)
		{
			break; /* STOP THE WHOLE LOOP */
		}
		printf("%d ", i);
	}
	printf("\n");

	printf("continue at 4: ");
	for (i = 0; i < 10; i++)
	{
		if (i == 4)
		{
			continue; /* SKIP ONLY THIS ROUND */
		}
		printf("%d ", i);
	}
	printf("\n");

	printf("while + continue: ");
	i = 0;
	while (i < 10)
	{
		if (i == 4)
		{
			i++; /* IN A WHILE LOOP, STEP FORWARD BEFORE CONTINUE */
			continue;
		}
		printf("%d ", i);
		i++;
	}
	printf("\n");

	return 0;
}
