/* STORAGE CLASSES: GLOBAL AND STATIC VARIABLES LIVE FOR THE WHOLE RUN, LOCAL ONES ONLY DURING A CALL */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define N 5 /* HOW MANY CALLS */

int count; /* GLOBAL: STATIC STORAGE, STARTS AT 0 */
void func(int x, int y);

int main(void)
{
	register int i; /* REGISTER: ONLY A HINT FOR SPEED */

	for (i = 0; i < N; i++)
	{
		func(i, count * 2 + 1);
	}
	printf("no. of calls: %d\n", count);

	return 0;
}

void func(int x, int y) /* PARAMETERS ARE LOCAL TOO */
{
	int z = count * 3;  /* AUTOMATIC: CREATED AT EVERY CALL, GONE AT THE END */
	static int state;   /* STATIC LOCAL: CREATED ONCE, KEEPS ITS VALUE, STARTS AT 0 */

	state = state + x * x + y - z;
	count++;
	printf("iteration %d: state = %d\n", count, state);
}
