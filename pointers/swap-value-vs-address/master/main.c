/* SWAP: PASSING VALUES CHANGES ONLY COPIES, PASSING ADDRESSES CHANGES THE ORIGINAL VARIABLES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

void swap_values(int x, int y) /* X AND Y ARE COPIES */
{
	int temp = x;

	x = y;
	y = temp;
}

void swap_addresses(int *x, int *y) /* X AND Y POINT TO THE CALLER'S VARIABLES */
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

int main(void)
{
	int a = 3, b = 7;

	swap_values(a, b);
	printf("after swap_values:    a = %d, b = %d (nothing changed)\n", a, b);

	swap_addresses(&a, &b); /* SEND THE ADDRESSES */
	printf("after swap_addresses: a = %d, b = %d\n", a, b);

	return 0;
}
