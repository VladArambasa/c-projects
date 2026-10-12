/* TWO'S COMPLEMENT: THE SAME 8 BITS READ AS UNSIGNED OR AS SIGNED */
#include <stdio.h> /* PRINTF, PUTCHAR */

void print_bits(unsigned char value)
{
	for (int i = 7; i >= 0; i--) /* BIT 7 (THE MOST SIGNIFICANT) FIRST */
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
}

int main(void)
{
	unsigned char patterns[7] = {0, 1, 127, 128, 129, 254, 255};

	printf("bits      unsigned  signed\n");
	for (int i = 0; i < 7; i++)
	{
		unsigned char u = patterns[i];
		signed char s = (signed char)u; /* SAME BITS READ AS SIGNED */

		print_bits(u);
		printf("  %8d  %6d\n", u, s);
	}

	printf("\n-1 stored in 8 bits: ");
	print_bits((unsigned char)-1); /* ALL EIGHT BITS ARE 1 */
	printf("\n");

	return 0;
}
