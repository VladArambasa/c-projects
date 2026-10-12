/* GRADE FROM A PERCENTAGE: A (90-100), B (80-89), C (70-79), D (60-69), F (BELOW 60) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	float percent = 0;

	printf("Enter the percentage (0-100): ");
	scanf("%f", &percent);

	if (percent < 0 || percent > 100)
	{
		printf("Invalid input\n");
	}
	else if (percent >= 90)
	{
		printf("Grade A\n");
	}
	else if (percent >= 80) /* HERE WE ALREADY KNOW IT IS BELOW 90 */
	{
		printf("Grade B\n");
	}
	else if (percent >= 70)
	{
		printf("Grade C\n");
	}
	else if (percent >= 60)
	{
		printf("Grade D\n");
	}
	else
	{
		printf("Grade F\n");
	}

	return 0;
}
