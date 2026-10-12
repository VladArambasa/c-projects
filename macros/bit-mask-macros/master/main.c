/* BIT MASK MACROS: SET, CLEAR, TOGGLE AND READ ONE BIT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define SET_BIT(VALUE, BIT) ((VALUE) | (1u << (BIT)))     /* OR WITH THE MASK: THE BIT BECOMES 1 */
#define CLEAR_BIT(VALUE, BIT) ((VALUE) & ~(1u << (BIT)))  /* AND WITH THE INVERTED MASK: IT BECOMES 0 */
#define TOGGLE_BIT(VALUE, BIT) ((VALUE) ^ (1u << (BIT)))  /* XOR WITH THE MASK: IT FLIPS */
#define READ_BIT(VALUE, BIT) (((VALUE) >> (BIT)) & 1u)    /* MOVE IT TO POSITION 0, KEEP ONLY IT */

void print_bits(unsigned char value)
{
	int i;

	for (i = 7; i >= 0; i--)
	{
		putchar(READ_BIT(value, i) ? '1' : '0');
	}
	putchar('\n');
}

int main(void)
{
	unsigned char reg = 0x0F; /* 0000 1111 */

	printf("start:           ");
	print_bits(reg);

	reg = SET_BIT(reg, 7);
	printf("set bit 7:       ");
	print_bits(reg);

	reg = CLEAR_BIT(reg, 0);
	printf("clear bit 0:     ");
	print_bits(reg);

	reg = TOGGLE_BIT(reg, 4);
	printf("toggle bit 4:    ");
	print_bits(reg);

	printf("bit 7 = %u, bit 0 = %u\n", READ_BIT(reg, 7), READ_BIT(reg, 0));

	return 0;
}
