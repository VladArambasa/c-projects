/* DAY OF THE WEEK FROM ITS NUMBER, USING SWITCH */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int day = 0;

	printf("Enter a number (1-7): ");
	scanf("%d", &day);

	switch (day) /* JUMPS TO THE MATCHING CASE */
	{
	case 1:
		printf("Monday\n");
		break; /* WITHOUT BREAK THE NEXT CASE WOULD RUN TOO */
	case 2:
		printf("Tuesday\n");
		break;
	case 3:
		printf("Wednesday\n");
		break;
	case 4:
		printf("Thursday\n");
		break;
	case 5:
		printf("Friday\n");
		break;
	case 6:
		printf("Saturday\n");
		break;
	case 7:
		printf("Sunday\n");
		break;
	default: /* NO CASE MATCHED */
		printf("Invalid input\n");
	}

	return 0;
}
