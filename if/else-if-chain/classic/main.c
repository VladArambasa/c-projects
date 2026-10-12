/* ELSE IF: CONDITIONS ARE CHECKED IN ORDER, THE FIRST TRUE ONE WINS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int time = 0;

	printf("Enter the hour (0-23): ");
	scanf("%d", &time);

	if (time < 10)
	{
		printf("Good morning.\n");
	}
	else if (time < 20) /* CHECKED ONLY WHEN THE FIRST CONDITION IS FALSE */
	{
		printf("Good day.\n");
	}
	else /* NONE OF THE CONDITIONS WAS TRUE */
	{
		printf("Good evening.\n");
	}

	return 0;
}
