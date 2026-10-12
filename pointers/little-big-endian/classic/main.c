/* LITTLE OR BIG ENDIAN: WHICH BYTE OF A MULTI-BYTE VALUE IS STORED AT THE LOWEST ADDRESS? */
#include <stdio.h> /* PRINTF */

#define BYTE unsigned char /* DATA TYPE FOR ONE BYTE: 8 BITS, NO SIGN */

int main(void)
{
	unsigned int x = 1; /* 4 BYTES: 00 00 00 01, THE 1 IS IN THE LEAST SIGNIFICANT BYTE */

	/* &X          -> THE ADDRESS OF X
	 * (BYTE *)&X  -> THE SAME ADDRESS, SEEN AS A POINTER TO ONE BYTE
	 * *(BYTE *)&X -> THE VALUE OF THE BYTE AT THE LOWEST ADDRESS */
	if (*(BYTE *)&x == 1)
	{
		printf("Little Endian\n"); /* THE LEAST SIGNIFICANT BYTE COMES FIRST */
	}
	else
	{
		printf("Big Endian\n"); /* THE MOST SIGNIFICANT BYTE COMES FIRST */
	}

	return 0;
}
