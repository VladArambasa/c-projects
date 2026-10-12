/* UNION BYTE VIEW: THE SAME 4 BYTES SEEN AS ONE INT OR AS 4 SEPARATE BYTES (ASSUMES A 4-BYTE INT) */
#include <stdio.h> /* PRINTF */

union word
{
	unsigned int value;
	unsigned char bytes[4];
};

int main(void)
{
	union word w;
	int i;

	w.value = 0x11223344;

	for (i = 0; i < 4; i++) /* LOWEST ADDRESS FIRST */
	{
		printf("bytes[%d] = 0x%02X\n", i, w.bytes[i]);
	}

	if (w.bytes[0] == 0x44)
	{
		printf("Little endian: the low byte 0x44 is stored first\n");
	}
	else
	{
		printf("Big endian: the high byte 0x11 is stored first\n");
	}

	printf("Big endian order (as sent over a network):");
	for (i = 3; i >= 0; i--)
	{
		printf(" %02X", w.bytes[i]); /* ON A LITTLE ENDIAN MACHINE: REVERSE THE BYTES */
	}
	printf("\n");

	return 0;
}
