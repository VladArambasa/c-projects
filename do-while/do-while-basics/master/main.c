/* DO-WHILE: THE BODY RUNS FIRST AND THE CONDITION IS CHECKED AFTER, SO IT RUNS AT LEAST ONCE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int i = 0;

	do
	{
		printf("%d\n", i);
		i++;
	} while (i < 5); /* NOTE THE SEMICOLON */

	i = 10;
	do
	{
		printf("Runs once even though i < 5 is false (i = %d)\n", i);
	} while (i < 5);

	return 0;
}
