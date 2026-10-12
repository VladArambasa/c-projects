/* POINTERS AND ARRAYS: T[I], *(T + I), P[I] AND *(P + I) ALL MEAN THE SAME ELEMENT */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int t[5] = {10, 20, 30, 40, 50};
	int *p = t; /* THE ARRAY NAME IS THE ADDRESS OF ITS FIRST ELEMENT */
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("t[%d] = %d   *(t + %d) = %d   p[%d] = %d   *(p + %d) = %d\n",
		       i, t[i], i, *(t + i), i, p[i], i, *(p + i));
	}

	p++; /* ALLOWED: P IS A VARIABLE */
	/* T++;  NOT ALLOWED: THE ARRAY NAME IS A FIXED ADDRESS */
	printf("after p++, p[0] = %d\n", p[0]);

	return 0;
}
