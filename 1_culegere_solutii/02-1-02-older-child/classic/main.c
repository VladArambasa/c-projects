/* CULEGERE II.1.2 - OLDER CHILD
 * READ THE AGES OF TWO CHILDREN; PRINT WHICH CHILD IS OLDER AND THE AGE DIFFERENCE
 * EXAMPLE: 6 13 -> THE SECOND CHILD IS OLDER BY 7 YEARS
 * ASSUMPTION: IF THE AGES ARE EQUAL, THE PROGRAM SAYS THAT THE CHILDREN ARE THE SAME AGE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int age1 = 0, age2 = 0;

	printf("Ages of the two children: ");
	scanf("%d %d", &age1, &age2);

	/* THE DIFFERENCE IS ALWAYS THE BIGGER AGE MINUS THE SMALLER AGE */
	if (age1 > age2)
	{
		printf("The first child is older by %d years\n", age1 - age2);
	}
	else if (age2 > age1)
	{
		printf("The second child is older by %d years\n", age2 - age1);
	}
	else
	{
		printf("The children are the same age\n");
	}

	return 0;
}
