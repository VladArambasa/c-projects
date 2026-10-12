/* SUM OF ARGUMENTS: ADD THE INTEGERS GIVEN ON THE COMMAND LINE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(int argc, char *argv[])
{
	int sum = 0;

	if (argc < 2)
	{
		printf("Usage: %s 3 4 5\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) /* ARGV[0] IS THE PROGRAM NAME: SKIP IT */
	{
		sum = sum + atoi(argv[i]); /* TEXT TO INT: "12" GIVES 12, TEXT WITHOUT DIGITS GIVES 0 */
	}

	printf("Sum = %d\n", sum);
	return 0;
}
