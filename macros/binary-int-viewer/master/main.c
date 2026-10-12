/* BINARY INT VIEWER: READ AN INT AND PRINT ITS BITS, 8 PER BYTE, MOST SIGNIFICANT BYTE FIRST */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c" /* 8 CHARACTERS = 8 BITS */
#define BYTE_DT unsigned char                     /* BYTE DATA TYPE */

/* GIVES 8 CHARACTERS, '1' OR '0', ONE PER BIT, FROM BIT 7 DOWN TO BIT 0
 * A COMMENT MUST COME BEFORE THE BACKSLASH: THE BACKSLASH HAS TO BE THE LAST CHARACTER ON THE LINE */
#define BYTE_TO_BINARY(byte) \
	((byte) & 0x80 ? '1' : '0'), /* BIT 7: 1000 0000 */ \
	((byte) & 0x40 ? '1' : '0'), /* BIT 6: 0100 0000 */ \
	((byte) & 0x20 ? '1' : '0'), /* BIT 5: 0010 0000 */ \
	((byte) & 0x10 ? '1' : '0'), /* BIT 4: 0001 0000 */ \
	((byte) & 0x08 ? '1' : '0'), /* BIT 3: 0000 1000 */ \
	((byte) & 0x04 ? '1' : '0'), /* BIT 2: 0000 0100 */ \
	((byte) & 0x02 ? '1' : '0'), /* BIT 1: 0000 0010 */ \
	((byte) & 0x01 ? '1' : '0')  /* BIT 0: 0000 0001 */

int main(void)
{
	int a = 0;

	scanf("%d", &a); /* READ THE INT AS A BASE-10 NUMBER */

	BYTE_DT *p = (BYTE_DT *)&a; /* SEE THE INT AS SEPARATE BYTES: P + 1 IS THE NEXT BYTE */

	/* HIGHEST ADDRESS FIRST: ON LITTLE ENDIAN THAT IS THE MOST SIGNIFICANT BYTE */
	for (int i = sizeof(a) - 1; i >= 0; i--)
	{
		/* *(P + I) = BYTE NUMBER I OF THE INT, COUNTED FROM ITS LOWEST ADDRESS */
		printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(*(p + i)));
		printf(" "); /* SEPARATE THE BYTES */
	}
	printf("\n");

	return 0;
}
