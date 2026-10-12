/* USER INPUT: SCANF STORES WHAT THE USER TYPES INTO VARIABLES */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int age = 0;
	double height = 0;
	char name[30] = ""; /* ROOM FOR 29 LETTERS + THE TERMINATOR */

	printf("Enter your first name: ");
	scanf("%29s", name); /* NO & FOR ARRAYS: THE NAME IS ALREADY AN ADDRESS */

	printf("Enter your age: ");
	scanf("%d", &age); /* & GIVES SCANF THE ADDRESS OF THE VARIABLE */

	printf("Enter your height in meters: ");
	scanf("%lf", &height); /* SCANF NEEDS %LF FOR A DOUBLE (BOTH LETTERS LOWERCASE) */

	printf("Hello %s! You are %d years old and %.2f m tall.\n", name, age, height);

	return 0;
}
