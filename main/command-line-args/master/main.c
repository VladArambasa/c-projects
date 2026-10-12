/* COMMAND-LINE ARGUMENTS: MAIN RECEIVES THE WORDS TYPED AFTER THE PROGRAM NAME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(int argc, char *argv[]) /* ARGC = HOW MANY, ARGV = THE WORDS */
{
	printf("argc = %d\n", argc); /* AT LEAST 1: THE PROGRAM NAME */

	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]); /* ARGV[0] IS THE PROGRAM NAME */
	}

	return 0;
}
