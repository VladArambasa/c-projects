/* CONDITIONAL COMPILATION: THE PREPROCESSOR KEEPS OR DROPS PARTS OF THE CODE BEFORE COMPILING */
#include <stdio.h> /* PRINTF */

#define DEBUG   /* REMOVE THIS LINE AND REBUILD: THE DEBUG MESSAGES DISAPPEAR */
#define LEVEL 2 /* TRY 1 OR 3 */

int main(void)
{
	int i;
	int sum = 0;

	for (i = 1; i <= 3; i++)
	{
		sum = sum + i;
#ifdef DEBUG
		printf("[debug] i = %d, sum = %d\n", i, sum); /* COMPILED ONLY WHEN DEBUG IS DEFINED */
#endif
	}
	printf("sum = %d\n", sum);

#if LEVEL == 1
	printf("Level 1: beginner\n");
#elif LEVEL == 2
	printf("Level 2: intermediate\n");
#else
	printf("Level 3: advanced\n");
#endif

#ifndef VERSION
	printf("VERSION is not defined\n");
#endif

#if defined(DEBUG) && LEVEL > 1
	printf("Debug build above level 1\n");
#endif

	return 0;
}
