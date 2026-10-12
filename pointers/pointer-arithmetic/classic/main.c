/* POINTER ARITHMETIC: +1 MOVES TO THE NEXT ELEMENT, NOT TO THE NEXT BYTE */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int t[5] = {10, 20, 30, 40, 50};
	int *p = &t[0]; /* SAME AS P = T */
	int *q = &t[4];

	printf("*p = %d, *(p + 2) = %d\n", *p, *(p + 2));

	p++; /* NOW AT T[1] */
	q--; /* NOW AT T[3] */
	printf("after p++ and q--: *p = %d, *q = %d\n", *p, *q);

	printf("q - p = %d elements apart\n", (int)(q - p));
	printf("p < q is %d\n", p < q); /* COMPARE POINTERS INTO THE SAME ARRAY */
	printf("p + 1 is %d bytes after p (the size of an int)\n", (int)((char *)(p + 1) - (char *)p));

	return 0;
}
