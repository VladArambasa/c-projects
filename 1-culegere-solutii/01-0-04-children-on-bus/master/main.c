/* CULEGERE I.4 - CHILDREN ON THE BUS
 * 7 CHILDREN ARE ON A BUS; CHILDREN FROM TWO MORE SCHOOLS GET ON (THEIR NUMBERS ARE READ).
 * PRINT HOW MANY CHILDREN WENT ON THE TRIP
 * EXAMPLE: 15 20 -> 42 CHILDREN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int school1 = 0, school2 = 0, total;

	printf("Children from the two schools: ");
	scanf("%d %d", &school1, &school2);

	total = 7 + school1 + school2; /* 7 CHILDREN WERE ALREADY ON THE BUS */

	printf("%d children\n", total);

	return 0;
}
