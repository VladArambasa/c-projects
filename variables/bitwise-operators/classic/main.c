/* BITWISE OPERATORS: & | ^ ~ WORK ON EACH BIT */
#include <stdio.h> /* PRINTF, PUTCHAR */

void print_bits(unsigned char value)
{
	for (int i = 7; i >= 0; i--)
	{
		if (value & (1 << i))
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
	}
	printf("  (%d)\n", value);
}

int main(void)
{
	unsigned char a = 0x2D; /* 0010 1101 */
	unsigned char b = 0xCB; /* 1100 1011 */

	printf("a     = ");
	print_bits(a);
	printf("b     = ");
	print_bits(b);
	printf("a & b = ");
	print_bits(a & b); /* 1 WHERE BOTH BITS ARE 1 */
	printf("a | b = ");
	print_bits(a | b); /* 1 WHERE AT LEAST ONE BIT IS 1 */
	printf("a ^ b = ");
	print_bits(a ^ b); /* 1 WHERE THE BITS DIFFER */
	printf("~a    = ");
	print_bits(~a);    /* EVERY BIT FLIPPED */

	return 0;
}
