/* SWAP TWO NUMBERS USING A THIRD VARIABLE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, temp;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	temp = a; /* TEMP KEEPS THE OLD VALUE OF A */
	a = b;    /* A GETS B */
	b = temp; /* B GETS THE OLD A */

	printf("After swap: a = %d, b = %d\n", a, b);

	return 0;
}
