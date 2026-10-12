/* BIT-FIELDS: STORE SMALL NUMBERS IN JUST A FEW BITS */
#include <stdio.h> /* PRINTF */

struct date
{
	unsigned int day : 5;   /* 0..31 NEEDS 5 BITS */
	unsigned int month : 4; /* 0..15 NEEDS 4 BITS */
	unsigned int year : 12; /* 0..4095 NEEDS 12 BITS */
};

int main(void)
{
	struct date d;
	int too_big = 33;

	d.day = 11;
	d.month = 10;
	d.year = 2026;

	printf("Date: %d.%d.%d\n", d.day, d.month, d.year);
	printf("sizeof(struct date) = %zu bytes instead of %zu\n", sizeof(struct date), 3 * sizeof(int));

	d.day = too_big; /* 33 NEEDS 6 BITS: ONLY THE LOW 5 ARE KEPT (33 - 32 = 1) */
	printf("day after storing 33: %d\n", d.day);

	return 0;
}
