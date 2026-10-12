/* SHARING DATA THROUGH A GLOBAL VARIABLE: EVERY FUNCTION IN THE FILE CAN READ AND CHANGE IT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int count = 0; /* GLOBAL: DECLARED OUTSIDE ALL FUNCTIONS */

void f1(void);
void f2(void);

int main(void)
{
	count++;
	printf("main: count = %d\n", count);
	f1();
	printf("back in main: count = %d\n", count);

	return 0;
}

void f1(void)
{
	count++;
	printf("f1:   count = %d\n", count);
	f2();
}

void f2(void)
{
	count++;
	printf("f2:   count = %d\n", count);
}
