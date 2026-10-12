/* SCOPE AND LIFETIME: WHERE A NAME CAN BE USED AND HOW LONG THE VARIABLE EXISTS */
#include <stdio.h> /* PRINTF */

int value = 1; /* GLOBAL: VISIBLE IN THE WHOLE FILE, EXISTS DURING THE WHOLE RUN */

void counter(void)
{
	static int calls = 0; /* KEEPS ITS VALUE BETWEEN CALLS */
	int temp = 0;         /* CREATED AGAIN AT EVERY CALL */

	calls++;
	temp++;
	printf("calls = %d, temp = %d\n", calls, temp);
}

int main(void)
{
	printf("global value = %d\n", value);
	{
		int value = 2; /* SAME NAME IN AN INNER BLOCK: HIDES THE GLOBAL ONE */
		printf("inner value  = %d\n", value);
	} /* THE INNER VALUE ENDS HERE */
	printf("global again = %d\n", value);

	counter();
	counter();
	counter();

	return 0;
}
