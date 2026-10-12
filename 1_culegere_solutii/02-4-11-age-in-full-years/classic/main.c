/* CULEGERE II.4.11 - AGE IN FULL YEARS
 * READ TODAY'S DATE AND A PERSON'S DATE OF BIRTH (YEAR, MONTH, DAY) AND PRINT THE AGE OF THE
 * PERSON IN COMPLETED YEARS
 * EXAMPLE: 2005 10 25 AND 1960 11 2 -> 44 YEARS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int y1 = 0, m1 = 0, d1 = 0; /* TODAY */
	int y2 = 0, m2 = 0, d2 = 0; /* DATE OF BIRTH */
	int age;

	printf("Current date (year month day): ");
	scanf("%d %d %d", &y1, &m1, &d1);
	printf("Date of birth (year month day): ");
	scanf("%d %d %d", &y2, &m2, &d2);

	age = y1 - y2;
	/* IF THIS YEAR'S BIRTHDAY HAS NOT COME YET, THE LAST YEAR IS NOT COMPLETE */
	if (m1 < m2 || (m1 == m2 && d1 < d2))
	{
		age = age - 1;
	}

	printf("%d years\n", age);

	return 0;
}
