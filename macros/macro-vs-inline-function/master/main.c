/* MACRO OR INLINE FUNCTION? THE MACRO MAY EVALUATE AN ARGUMENT TWICE, THE FUNCTION ONLY ONCE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX_MACRO(A, B) ((A) > (B) ? (A) : (B))

/* INLINE: A HINT TO PASTE THE BODY AT THE CALL; STATIC: VISIBLE IN THIS FILE ONLY */
static inline int max_inline(int a, int b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	int a, b, x;

	a = 5;
	b = 2;
	x = MAX_MACRO(a++, b++);
	printf("macro:  x = %d, a = %d, b = %d\n", x, a, b); /* A WAS INCREMENTED TWICE */

	a = 5;
	b = 2;
	x = max_inline(a++, b++);
	printf("inline: x = %d, a = %d, b = %d\n", x, a, b); /* EACH ARGUMENT IS EVALUATED ONCE */

	return 0;
}
