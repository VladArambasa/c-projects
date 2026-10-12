/* DAY OF THE WEEK FROM ITS NUMBER (V2): ONE TABLE LOOKUP INSTEAD OF A SWITCH WITH 7 CASES */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int day = 0;

	printf("Enter a number (1-7): ");
	scanf("%d", &day);

	if (day >= 1 && day <= 7)
	{
		printf("%s\n", days[day - 1]); /* THE ARRAY STARTS AT 0, THE DAYS AT 1 */
	}
	else
	{
		printf("Invalid input\n");
	}

	return 0;
}
