/* BYTE DUMP: LOOK AT THE RAW BYTES OF ANY VARIABLE THROUGH AN UNSIGNED CHAR POINTER */
#include <stdio.h> /* PRINTF */

void dump(char *name, void *address, int size)
{
	unsigned char *p = address; /* ONE BYTE AT A TIME */
	int i;

	printf("%-12s:", name);
	for (i = 0; i < size; i++)
	{
		printf(" %02X", p[i]); /* TWO HEXADECIMAL DIGITS PER BYTE */
	}
	printf("\n");
}

int main(void)
{
	int one = 1;
	int minus_one = -1;
	float f = 1.0;
	double d = -2.5;
	char text[] = "Hi!";

	dump("int 1", &one, sizeof(one));
	dump("int -1", &minus_one, sizeof(minus_one)); /* TWO'S COMPLEMENT: ALL BITS 1 */
	/* IEEE 754: SIGN, EXPONENT, MANTISSA; LITTLE ENDIAN PRINTS THE BYTES IN REVERSE */
	dump("float 1.0", &f, sizeof(f));
	dump("double -2.5", &d, sizeof(d));
	dump("\"Hi!\"", text, sizeof(text));           /* CHARACTER CODES AND THE TERMINATOR */

	return 0;
}
