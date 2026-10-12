/* NESTED STRUCTURES: A MEMBER CAN ITSELF BE A STRUCTURE */
#include <stdio.h> /* PRINTF */

struct date
{
	int day, month, year;
};

struct student
{
	char name[20];
	struct date born; /* A STRUCTURE INSIDE A STRUCTURE */
	float grade;
};

int main(void)
{
	struct student s = {"Ana", {15, 3, 2012}, 9.50}; /* INNER BRACES FOR THE INNER STRUCTURE */

	s.born.year = 2013; /* TWO DOTS: STUDENT, THEN DATE */

	printf("%s was born on %02d.%02d.%d\n", s.name, s.born.day, s.born.month, s.born.year);
	printf("Grade: %.2f\n", s.grade);

	return 0;
}
