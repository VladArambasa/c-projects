/* IF AND ELSE: RUN CODE ONLY WHEN A CONDITION IS TRUE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int x = 20, y = 18;
	int time = 0;

	if (x > y) /* TRUE, SO THE BLOCK RUNS */
	{
		printf("x is greater than y\n");
	}

	printf("Enter the hour (0-23): ");
	scanf("%d", &time);

	if (time < 18)
	{
		printf("Good day.\n");
	}
	else /* RUNS WHEN THE CONDITION IS FALSE */
	{
		printf("Good evening.\n");
	}

	return 0;
}
