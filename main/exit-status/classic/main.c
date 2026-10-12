/* EXIT STATUS: THE VALUE RETURNED BY MAIN GOES BACK TO THE SHELL, WHICH STORES IT IN $? */
#include <stdio.h>  /* PRINTF, SCANF */
#include <stdlib.h> /* EXIT, EXIT_SUCCESS, EXIT_FAILURE */

void check_age(int age)
{
	if (age < 0)
	{
		printf("Negative age: exit(EXIT_FAILURE)\n");
		exit(EXIT_FAILURE); /* ENDS THE PROGRAM FROM ANY FUNCTION */
	}
}

int main(void)
{
	int age = 0;

	printf("Enter your age: ");
	scanf("%d", &age);

	check_age(age); /* DOES NOT COME BACK IF THE AGE IS NEGATIVE */

	printf("Age %d accepted: return EXIT_SUCCESS\n", age);
	return EXIT_SUCCESS; /* SAME AS RETURN 0 */
}
