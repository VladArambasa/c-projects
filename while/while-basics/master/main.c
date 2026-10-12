/* WHILE LOOP: REPEAT AS LONG AS THE CONDITION IS TRUE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int i = 0;

	while (i < 5) /* CHECKED BEFORE EVERY ROUND */
	{
		printf("%d\n", i);
		i++; /* WITHOUT THIS THE LOOP WOULD NEVER END */
	}

	return 0;
}
