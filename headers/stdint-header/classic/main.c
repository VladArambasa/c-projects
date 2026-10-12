/* STDINT.H: INTEGER TYPES WITH AN EXACT WIDTH, THE SAME ON EVERY MACHINE */
#include <stdio.h>    /* PRINTF */
#include <stdint.h>   /* UINT8_T, INT16_T, INT32_T, UINT64_T AND THEIR LIMITS */
#include <inttypes.h> /* PRINTF FORMATS FOR THE EXACT-WIDTH TYPES */

int main(void)
{
	uint8_t byte = 255;           /* EXACTLY 8 BITS, NO SIGN */
	int16_t small = INT16_MAX;    /* EXACTLY 16 BITS */
	int32_t big = INT32_MAX;      /* EXACTLY 32 BITS */
	uint64_t huge = UINT64_MAX;   /* EXACTLY 64 BITS, NO SIGN */

	byte = byte + 1; /* ONLY 8 BITS: 255 + 1 WRAPS AROUND TO 0 */

	printf("uint8_t 255 + 1 = %d\n", byte);
	printf("INT16_MAX  = %d\n", small);
	printf("INT32_MAX  = %" PRId32 "\n", big);
	printf("UINT64_MAX = %" PRIu64 "\n", huge);
	printf("sizes: %zu %zu %zu %zu bytes\n",
	       sizeof(int8_t), sizeof(int16_t), sizeof(int32_t), sizeof(int64_t));

	return 0;
}
