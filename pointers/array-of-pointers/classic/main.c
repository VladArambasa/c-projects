/* ARRAY OF POINTERS: EACH ELEMENT POINTS TO A STRING; A POINTER TO POINTER CAN WALK THROUGH THEM */
#include <stdio.h> /* PRINTF */

int main(void)
{
	char *days[5] = {"Monday", "Tue", "Wednesday", "Thu", "Fri"}; /* 5 POINTERS, STRINGS OF ANY LENGTH */
	char grid[5][10] = {"Monday", "Tue", "Wednesday", "Thu", "Fri"}; /* 5 ROWS OF 10 CHARACTERS EACH */
	char **pp = days; /* POINTS TO THE FIRST POINTER */
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%s ", days[i]);
	}
	printf("\n");

	pp++; /* NOW AT THE SECOND POINTER */
	printf("*pp = %s, **pp = %c\n", *pp, **pp); /* THE STRING, THEN ITS FIRST CHARACTER */

	printf("sizeof(days) = %zu (5 pointers), sizeof(grid) = %zu (5 x 10 chars)\n",
	       sizeof(days), sizeof(grid));
	printf("grid[2] = %s\n", grid[2]);

	return 0;
}
