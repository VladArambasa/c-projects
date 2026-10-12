/* PACK TWO SMALL VALUES INTO ONE BYTE, THEN UNPACK THEM
 * BYTE LAYOUT: BIT 7 UNUSED, BITS 6-4 = A (0 TO 7), BITS 3-0 = B (0 TO 15) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define PACK(A, B) ((((A) & 0x07) << 4) | ((B) & 0x0F)) /* FIELD A MOVES 4 PLACES LEFT, FIELD B STAYS RIGHT */
#define GET_A(BYTE) (((BYTE) >> 4) & 0x07)                /* MOVE FIELD A BACK DOWN, KEEP 3 BITS */
#define GET_B(BYTE) ((BYTE) & 0x0F)                       /* KEEP THE LOW 4 BITS */

int main(void)
{
	int a = 5, b = 12;
	unsigned char packed;

	packed = PACK(a, b);
	printf("a = %d, b = %d -> packed byte = 0x%02X\n", a, b, packed);
	printf("unpacked: a = %d, b = %d\n", GET_A(packed), GET_B(packed));

	return 0;
}
